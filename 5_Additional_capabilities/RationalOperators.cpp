struct Rational
{
    Rational(int numerator = 0, int denominator = 1);
 
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);
 
    void neg();
    void inv();
    double to_double() const;
 
    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);
 
    Rational operator-() const;
    Rational operator+() const;
    
   Rational operator+(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(rational);
        return r;
    }
    Rational operator+(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.add(Rational(d));
        return r;
    }
    friend Rational operator+(int d, const Rational & rational) {
        return rational + d;
    }
    Rational operator-(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(rational);
        return r;
    }
    Rational operator-(double d) const {
        Rational r(this->numerator_, this->denominator_);
        r.sub(Rational(d));
        return r;
    }
    friend Rational operator-(int d, const Rational & rational) {
        return -(rational - d);
    }
    Rational operator*(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(rational);
        return r;
    }
    Rational operator*(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.mul(Rational(d));
        return r;
    }
    friend Rational operator*(int d, const Rational & rational) {
        return rational * d;
    }
    Rational operator/(const Rational & rational) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(rational);
        return r;
    }
    Rational operator/(int d) const {
        Rational r(this->numerator_, this->denominator_);
        r.div(Rational(d));
        return r;
    }
    friend Rational operator/(int d, const Rational & rational) {
        return Rational(d)/rational;
    }
private:
    int numerator_;
    unsigned denominator_;
};