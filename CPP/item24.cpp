#include <iostream>

class Rational {
    public:
        Rational(int a, int b);
        int numerator()const;
        int denominator()const;
    private:
        int n;
        int d;
};

Rational::Rational(int a, int b)
{
    n = a;
    d = b;
}

int Rational::numerator() const{
    return n;
}

int Rational::denominator() const{
    return d;
}

void printRational(Rational& r) {
    std::cout << r.numerator() << " / " << r.denominator() << std::endl;
}

const Rational operator*(const Rational& lhs, const Rational& rhs){
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

const Rational operator*(int a, const Rational& rhs) {
    return Rational(a * rhs.numerator(), a * rhs.denominator());
}

const Rational operator*(const Rational& lhs, int b) {
    return Rational(lhs.numerator() * b, lhs.denominator() * b);
}

int main ()
{
    Rational one_five(1, 5);
    Rational one_two(1, 2);

    //이렇게 다양한 연산을 하려면 비멤버 함수로 해야 함
    // 상수 * 객체, 객체 * 상수, 객체 * 객체
    Rational result2 = 2 * one_five;

    Rational result3 = one_two * 2;

    Rational result = result2 * result3;

    printRational(result);
}