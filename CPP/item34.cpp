#include <iostream>

//인터페이스 상속과 구현 상속의 차이를 제대로 파악하고 구별

//순수 가상 함수를 선언하는 목적은 파생 클래스에게 함수의 인터페이스만을 물려주려는 것이다. 순수 가상 함수는 파생 클래스에서 새롭게 정의되어야 한다.
//물론 순수 가상 함수에도 정의를 제공할 수 있다. 단, 반드시 클래스 이름을 한정자로 붙여 주여야 한다.
/*
error 함수를 보자. 단순 가상 함수를 선언하는 목적은 파생 클래스로 하여금 함수의 인터페이스뿐만 아니라 그 함수의 기본 구현도 물려받게 하자는 것이다.
즉, "error 함수는 당신이 직접 구현해야 하지만, 굳이 새로 만들 생각이 없다면 Shape 클래스에 있는 기본 버전을 써라" 라는 뜻이다

비가상 함수인 objectID를 보면
멤버 함수가 비가상 함수로 되어 있다는 것은, 클래스 파생에 상관 없이 변하지 않는 동작을 지정하는데 쓰인다.
즉, 비가상 함수를 선언하는 목적은 함수 인터페이스와 더불어 그 함수의 필수적인 구현을 물려받게 하는 것이다.

클래스를 설계할 때는 모든 함수를 가상함수로 만들거나 모든 함수를 비가상 함수로 만드는 실수를 하지 않도록!!
*/
class Shape
{
public:
	virtual void draw() const = 0;
	virtual void error(const std::string& msg) {}
	int objectID() const;
};

void Shape::draw() const
{
	std::cout << "Draw Shape" << std::endl;
}

class Rectangle: public Shape 
{
public:
	void draw() const override
	{
		std::cout << "Draw Rectangle" << std::endl;
	} 
};
class Ellipse: public Shape 
{
	public:
	void draw() const override
	{
		
	} 
};



int main()
{
	Shape *ps1 = new Rectangle;
	ps1->Shape::draw(); // Draw Shape

	Rectangle *ps2 = new Rectangle;
	ps2->draw(); // Draw Rectangle
}