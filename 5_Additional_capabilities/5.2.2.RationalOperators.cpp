// task 5.2.2.
struct Rational  // определяем класс
{
    Rational(int numerator = 0, int denominator = 1);  // устанавливаем две переменные со значениями по умолчанию

    // методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно
    void add(Rational rational); // прибавляют к нему число
    void sub(Rational rational); // отнимают число
    void mul(Rational rational); // умножают на число
    void div(Rational rational); // делят на число

    void neg();  // метод neg меняет знак на противоположный
    void inv();
    double to_double() const;
 
    Rational& operator+=(Rational rational);  // определяем оператор сложения "+="
    Rational& operator-=(Rational rational);  // определяем оператор вычитания "-="
    Rational& operator*=(Rational rational);  // определяем оператор умножения "*="
    Rational& operator/=(Rational rational);  // определяем оператор деления "/="
 
    Rational operator-() const;  // определяем оператор смены знака -
    Rational operator+() const;  // определяем оператор смены знака +

   // определяем оператор сложения двух чисел (числителя и знаменателя)
   Rational operator+(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);  // получаем числитель и знаменатель
        r.add(rational);  // сложение чисел
        return r;  // возвращаем результат
    }

    // определяем оператор сложения (к значениям числителя и знаменателя добавляется целое число)
    Rational operator+(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(Rational(d));
        return r;  // возвращаем результат
    }

    // определяем оператор сложения (к значениям числителя и знаменателя добавляется целое число)
    friend Rational operator+(int d, const Rational & rational) {
        return rational + d;  // возвращаем результат
    }
    Rational operator-(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(rational);
        return r;  // возвращаем результат
    }
    Rational operator-(double d) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(Rational(d));
        return r;  // возвращаем результат
    }
    friend Rational operator-(int d, const Rational & rational) {
        return -(rational - d);  // возвращаем результат
    }
    Rational operator*(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(rational);
        return r;  // возвращаем результат
    }
    Rational operator*(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(Rational(d));
        return r;  // возвращаем результат
    }
    friend Rational operator*(int d, const Rational & rational) {
        return rational * d;  // возвращаем результат
    }
    Rational operator/(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(rational);
        return r;  // возвращаем результат
    }
    Rational operator/(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(Rational(d));
        return r;  // возвращаем результат
    }
    friend Rational operator/(int d, const Rational & rational) {
        return Rational(d)/rational;  // возвращаем результат
    }
private:
    int numerator_;
    unsigned denominator_;
};