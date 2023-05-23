// task 5.3.1.
// Структура Expression, Number, BinaryOperation объявлены.
struct Expression;
struct Number;
struct BinaryOperation;

// Структура ScopedPtr реализует умный указатель с автоматическим освобождением памяти.
struct ScopedPtr {
    // реализуйте следующие методы:

    // Конструктор ScopedPtr принимает указатель на объект типа Expression. Если указатель не передан, то присваивается значение 0.
    explicit ScopedPtr(Expression *ptr = 0) {
        this->ptr_=ptr;
    }

    // Деструктор ScopedPtr освобождает память, выделенную для объекта, на который указывает ptr_.
    ~ScopedPtr() {
        delete  ptr_;
    }

    // Метод get() возвращает указатель на объект Expression.
    Expression* get() const {
        return ptr_;
    }
    // Метод release() возвращает указатель на объект Expression и обнуляет ptr_.
    Expression* release() {
        Expression * ptr = this->ptr_;
        this->ptr_ = NULL;
        return ptr;
    }

    // Метод reset() освобождает память, выделенную для объекта, на который указывает ptr_, и затем присваивает ptr_ новое значение.
    void reset(Expression *ptr = 0) {
        delete this->ptr_;
        this->ptr_ = ptr;
    }

    // Оператор * возвращает ссылку на объект, на который указывает ptr_.
    Expression& operator*() const {
        return *ptr_;
    }

    // Оператор -> возвращает указатель на объект, на который указывает ptr_.
    Expression* operator->() const {
        return ptr_;
    }

// Оператор присваивания и конструктор копирования не реализованы (приватные и не определены), что запрещает копирование
// объектов ScopedPtr и присваивание одного объекта другому.
private:
    ScopedPtr& operator=(const ScopedPtr & other) {} //оператор присваивания
    ScopedPtr(const ScopedPtr & other) {} //конструктор копирования
    Expression *ptr_;
};