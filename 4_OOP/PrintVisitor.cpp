/*
struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value);
    double evaluate() const;

    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right);
    ~BinaryOperation();
    double evaluate() const;

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
*/

#include <iostream>

/* Этот класс вам нужно реализовать */
struct PrintVisitor: Visitor {

    void visitNumber(Number const * number) {
        double x = number->evaluate();
        if(x < 0)
            std::cout << "(" << x << ")";
        else
            std::cout << x ;
    }

    void visitBinaryOperation(BinaryOperation const * bop) {
        bool is_prev = this->is;  //исходное
        char c = bop->get_op();
        bool is_cur = is_prev && (c == '-' || c == '+'); //снаружи * или /, а у нас + или - => нужны скобки
        if(is_cur)
            std::cout << "(";


        this->is = c=='*'||c=='/';   //сообщаем внутрь, что у нас приоритетная операция
        bop->get_left()->visit(this);

        std::cout << c;

        this->is = c=='*'||c =='/'; //сообщаем внутрь, что у нас приоритетная операция
        bop->get_right()->visit(this);

        if(is_cur)
            std::cout << ")";
        this->is = is_prev;      //вернем
    }
private:
    bool is=false;
};