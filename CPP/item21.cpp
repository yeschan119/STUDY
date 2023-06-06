#include <iostream>
#include <string>

//함수에서 객체를 반환해야 할 경우에 참조자를 반환하지 말자!!!

class Rational
{
    public:
        int n;
        int d;
        Rational(){
            n = 0;
            d = 0;
        }

        Rational(int a, int b){
            n = a;
            d = b;
        }
};

const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
    //이 경우 result가 리턴되는 시점에 result 본체는 함수에서 사라지기 때문에 Dangling Pointer가 됨
    Rational result(lhs.n * rhs.n, lhs.d * rhs.d);

    return result;
}

const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
    Rational * result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
    //result가 정상적으로 리턴되려면 new로 생성한 result는 result 리턴 시점까지 살아 있어야 함
    //그럼 리턴 후에 new로 생성된 result는 어디서 delete함?
    // Memory Leak
    return *result;
}

const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
    //result를 유지하려고 static로 정한 것인데 이러면 대환장 파티임
    //if ((a*b) == (c*d))가 수행되면 항상 true
    //이유는 두 operator의 결과값은 같은 static 객체인 result가 되기 때문.
    static Rational result;
    result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);

    return result;
}