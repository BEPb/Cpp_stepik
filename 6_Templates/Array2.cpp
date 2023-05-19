#include <iostream>
using namespace std;

/*
 * В предыдущей версии предполагается,
 * что для типа T определен оператор присваивания или он ему не нужен
 * (например, для примитивных типов он не нужен).
 * При создании шаблонных классов контейнеров (вроде Array и не только)
 * разумно стараться минимизировать требования к типам шаблонных параметров.
 * Поэтому усложним задачу, реализуйте класс Array не полагаясь на то,
 * что для типа T определен оператор присваивания.
 * Hints: используйте placement new и явный вызов деструктора,
 * чтобы создавать и уничтожать объекты,
 * аллоцировать правильно выровненную память можно с помощью new char[N * sizeof(T)],
 * где N - количество элементов массива.
 * */


#include <cstddef>
template <typename T>
class Array
{
    // Список операций:
    //
    // Array(size_t size, const T& value = T())
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //
    // Array()
    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
    //
    // Array(const Array &)
    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присвивания не определен.
    //
    // ~Array()
    //   деструктор, если он вам необходим.
    //
    // Array& operator=(...)
    //   оператор присваивания.
    //
    // size_t size() const
    //   возвращает размер массива (количество
    //                              элемнтов).
    //
    // T& operator[](size_t)
    // const T& operator[](size_t) const
    //   две версии оператора доступа по индексу.

    public:
    Array(size_t size, const T& value = T()) {
        size_ = size;
        data_ = (T*) new char[size_ * sizeof(T)];
        for (size_t i = 0; i != size_; ++i){
            new (data_ + i) T(value);
        }
    }
    Array() {
        size_ = 0;
//        data_ = (T*) new char[size_ * sizeof(T)];
        data_ = 0;
    }
    Array(const Array & obj) {
        size_ = obj.size();
        data_ = (T*) new char[size_ * sizeof(T)];
        for (size_t i = 0; i != size_; ++i) {
            new (data_ + i) T(obj[i]);
        }
    }
    Array& operator=(const Array & obj){
        if (this != &obj) {
            mem_free();
            size_ = obj.size();
            data_ = (T*) new char[size_ * sizeof(T)];
            for (size_t i = 0; i != size_; ++i) {
                new (data_ + i) T(obj[i]);
            }
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }
    T& operator[](size_t i) {
        //return data_[i]; равносильно:
        return *(data_ + i);
    }
    const T& operator[](size_t i) const {
        //return data_[i]; равносильно:
        return *(data_ + i);
    }
    ~Array() {
        mem_free();
    }

    void mem_free(){
        for (size_t i = 0; i != size_; ++i) {
            data_[i].~T();
        }
        // собака порылась здесь!!
        delete [] (char *) data_;
    }

    private :
        size_t size_ ;
        T * data_ ;
};

struct NonCopyable {
    // copy and assignment not allowed
    NonCopyable(const int value ): value_(value) {};
    NonCopyable& operator=(const NonCopyable & obj) = delete;
private:
    int value_;
};