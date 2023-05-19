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
friend bool operator!=(Rational const & lhs, Rational const & rhs);
    friend bool operator==(Rational const & lhs, Rational const & rhs);
    friend bool operator<(Rational const & lhs, Rational const & rhs);
    friend bool operator>(Rational lhs, Rational rhs);
    friend bool operator<=(Rational lhs, Rational rhs);
    friend bool operator>=(Rational lhs, Rational rhs);
    
private:
    int numerator_;
    int denominator_;
};
 
Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);
 
 
bool operator==(Rational const & lhs, Rational const & rhs){
return ((int)lhs.numerator_*(int)rhs. denominator_)==((int)rhs.numerator_*(int)lhs.denominator_);
}
 bool operator!=(Rational const & lhs, Rational const & rhs){
return !(lhs==rhs);
}
 bool operator<(Rational const & lhs, Rational const & rhs){
return ((int)lhs.numerator_*(int)rhs.denominator_)<((int)rhs.numerator_*(int)lhs.denominator_);
}
 bool operator>(Rational lhs, Rational rhs){
return rhs<lhs;
}
 bool operator<=(Rational lhs, Rational rhs){
return !(lhs>rhs);
}
 bool operator>=(Rational lhs, Rational rhs){
return !(lhs<rhs);
}