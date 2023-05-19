// Эти классы реализовывать заново не нужно
struct ICloneable;
 
// Поле data_ типа T в классе ValueHolder
// открыто, к нему можно обращаться
template <typename T>
struct ValueHolder;
 
class Any{
public:
    // В классе Any должен быть конструктор,
    // который можно вызвать без параметров,
    // чтобы работал следующий код:
    //    Any empty; // empty ничего не хранит
    Any():ptr(0) {} 
 
    // Не забудьте про деструктор. Все выделенные
    // ресурсы нужно освободить.
    ~Any() {
        delete ptr;     
    }
 
    // В классе Any также должен быть конструктор
    // копирования (вам поможет метод clone
    // интерфейса ICloneable)
    Any(const Any & other):ptr(other.ptr ? other.ptr->clone() : 0) {}
    
    // В классе Any должен быть шаблонный
    // конструктор от одного параметра, чтобы
    // можно было создавать объекты типа Any,
    // например, следующим образом:
    //    Any i(10); // i хранит значение 10
    template<typename T>Any(const T val):ptr(new ValueHolder<T>(val)) {}
    
 
    // В классе должен быть оператор присваивания и/или
    // шаблонный оператор присваивания, чтобы работал
    // следующий код:
    //    Any copy(i); // copy хранит 10, как и i
    //    empty = copy; // empty хранит 10, как и copy
    //    empty = 0; // а теперь empty хранит 0
    Any & operator=(const Any & other) {
        if(this != &other) {
            delete ptr;
            ptr = other.ptr ? other.ptr->clone() : 0;
        }
 
        return *this;
    }
    template<typename T>Any & operator=(const T & val) {
        delete ptr;
        ptr = new ValueHolder<T>(val);
        
        return *this;
    }
    
 
    // Ну и наконец, мы хотим уметь получать хранимое
    // значение, для этого определите в классе Any
    // шаблонный метод cast, который возвращает
    // указатель на хранимое значение, или нулевой
    // указатель в случае несоответствия типов или
    // если объект Any ничего не хранит:
    //    int *iptr = i.cast<int>(); // *iptr == 10
    //    char *cptr = i.cast<char>(); // cptr == 0,
    //        // потому что i хранит int, а не char
    //    Any empty2;
    //    int *p = empty2.cast<int>(); // p == 0
    // При реализации используйте dynamic_cast,
    // который мы уже обсуждали ранее.
    template<typename T>T * cast() {
        if(ptr == 0)
            return 0;
        else {
            ValueHolder<T>* pvh = dynamic_cast<ValueHolder<T>*>(ptr);
            if(pvh == 0)
                return 0;
            else
                return &(pvh->data_);
        }
    }
    
    
private:
    ICloneable * ptr;
};