struct Expression {
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};
 
struct Number: public Expression {
    Number(double value): value(value) {}
    double evaluate() const { return value; }
    
private:
    double value;
};
 
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