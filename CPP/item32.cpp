#include <iostream>

//public 상속 모형은 반드시 "is-a(...는 ...의 일종이다)"를 따르도록 만들자

//어떤 Base 클래스로부터 Derived 클래스가 public 상속을 받았다면, Derived 클래스는 Base 클래스보다 더 특수한 개념을 나타내게 된다. 사용처가 제한된다고 봐도 좋다.
//public 상속이 신기한 이유는, 우리가 일반적으로 생각하고 있는 논리적인 개념과 충돌할 수 있기 때문이다. 예를 들어, 수학적으로는 직사각형이 정사각형을 포함하는 경우이므로 정사각형 클래스를 직사각형 클래스로부터 public 상속을 받게 사용할 수 있을 거라고 가정할 수 있다. 다음 코드를 보자.

class Rectangle
{
public:
	virtual void setHeight(int newHeight);
	virtual void setWidth(int newWidth);
	virtual void height() const;
	virtual void width() const;
};

// r 의 넓이를 늘리는 함수
void makeBigger(Rectangle& r)
{
	int oldHeight = r.height();
	r.setWidth(r.newWidth() + 10);
	assert(r.height() == oldHeight);
}

//위의 코드처럼, Rectangle 에서 통하는 코드가 Squre 에서는 에러를 낼 수도 있다. 따라서 public 상속을 할 때는 객체 지향의 관점에서 설계를 제대로 할 필요가 있다!

class Square : public Rectangle
{

};

int main() {
Square s;
// 높이와 너비가 달라서 단언문이 거짓!
makeBigger(s);

}