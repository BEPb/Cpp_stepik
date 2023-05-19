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
    
    Rational & operator+=(const Rational & rational) { 
        this->add(rational);            
        return *this; 
    }
    Rational & operator+=(int d)                      { 
        this->add(Rational(d));         
        return *this; 
    }
    
    Rational & operator-=(const Rational & rational) { 
        this->sub(rational);    
        return *this; 
    }
    Rational & operator-=(int d)                      { 
        this->sub(Rational(d)); 
        return *this; 
    }
    
    Rational & operator*=(const Rational & rational) { 
        this->mul(rational);
        return *this; 
    }
    Rational & operator*=(int d)                     { 
        this->mul(Rational(d)); 
        return *this; 
    }
    
    Rational & operator/=(const Rational & rational) { 
        this->div(rational);    
        return *this; 
    }
    Rational & operator/=(int d)                     { 
        this->div(Rational(d)); 
        return *this; 
    }
 
    Rational operator-() const { Rational r(this->numerator_, this->denominator_); r.neg(); return r; }
    Rational operator+() const { Rational r(this->numerator_, this->denominator_);          return r; }
 
private:
    int numerator_;
    unsigned denominator_;
};