#include <iostream>

template<typename T>
class Rational
{
    public:
        Rational(const T &numerator = 0, const T &denominator = 1);
        const T numerator() const;
        const T denominator() const;
        //friend로 비멤버 함수를 선언하면 인라인이 되기 때문에, 클래스가 커질 수 있다. 따라서 도우미 함수를 사용
        friend const Rational operator*(const Rational& lhs, const Rational& rhs)
        {
		// 프렌드 함수가 도우미 함수를 호출하게 만듦
            return doMultiply(lhs, rhs);
        }
};

// 도우미 함수 템플릿은 일반적으로 헤더 파일에 들어감
template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs)
{
	return Rational<T>(lhs.numerator() * rhs.numerator(),
	lhs.denominator() * rhs.denominator());
}

/*
template<typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs)
{
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}
*/

int main()
{
    Rational<int> oneHalf(1, 2);
    Rational<int> twoHalf(2, 6);
    Rational<int> result1 = oneHalf * twoHalf;  //이건 되는데

    // Rational 객체 대신 int가 입력되는 것을 보고 타입 변환이 일어나야 하는데...
    Rational<int> result2 = oneHalf * 2; // error 발생. 함수 탬플릿을 호출할 동안에는 암시적 타입 변환이 고려되지 않는다.
    //해결 방법은 비멤버함수를 friend로 넣으면 된다.
    //class안에 넣으면 클래스가 인스턴스화 될 당시 T의 정확한 정보를 알 수 있으므로 함수 호출시 탬플릿 인자 추론을 하지 않아도 됨.
    //클래스 안에 비멈버함수를 선언하는 유일한 방법은 friend이다.
}