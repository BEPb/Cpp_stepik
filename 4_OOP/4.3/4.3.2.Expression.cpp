// task 4.3.2.

// Структура Expression является абстрактным базовым классом
struct Expression {
    virtual double evaluate() const = 0; // объявлены виртуальная функция evaluate()
    virtual ~Expression() {}  // объявлен виртуальный деструктор
};

// Класс Number наследуется от Expression и имеет конструктор, который принимает значение типа double. Метод evaluate()
// возвращает значение числа.
struct Number: public Expression {
    Number(double value): value(value) {}
    double evaluate() const { return value; }
    
private:
    double value;
};



/*
Класс BinaryOperation также наследуется от Expression и имеет конструктор, который принимает указатели на левое и
правое выражения, а также символ операции. Метод evaluate() выполняет операцию, указанную символом, над левым и правым
выражениями, вызывая соответствующий метод evaluate() у каждого из них. В конце метод возвращает результат вычисления. В
 деструкторе удаляются указатели на левое и правое выражения.    */
struct BinaryOperation: Expression {
    BinaryOperation(Expression const * left, char op, Expression const * right) : left(left), op(op), right(right) {}
    double evaluate() const { 
        double t = left->evaluate();
        switch(op) {
            case '+':
                t += right->evaluate();
                break;
            case '-':
                t -= right->evaluate();
                break;
            case '*':
                t *= right->evaluate();
                break;
            default:
                t /= right->evaluate();
                break;
        }
        return t; 
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }
private:
    Expression const * left;
    Expression const * right;
    char op;
};