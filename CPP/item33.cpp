#include <iostream>

//1. 파생 클래스의 이름은 기본 클래스의 이름을 가린다. public 상속에서는 이런 이름 가림 현상은 바람직하지 않다.
//2. 가려진 이름을 다시 볼 수 있게 하는 방법으로, using 선언 혹은 전달 함수를 쓸 수 있다.

class Base
{
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int);
	virtual void mf2();

	void mf3();
	void mf3(double);
};

class Derived: public Base
{
public:
	virtual void mf1();
	void mf3();
	void mf4();
    // Base 에 있는 것들 중 mf1 과 mf3 를 이름으로 가진
	// 것들을 Derived 의 유효범위에서 볼 수 있도록 만듦
	using Base::mf1;
	using Base::mf3;
};


//그렇다면 이제 한 걸음 더 나아가보자. int 인자를 받는 mf1 함수와 인자를 받지 않는 mf1 함수가 Base 클래스에 정의되어 있고,
//Derived 클래스는 mf1 을 찾을 때 인자를 받지 않는 mf1 함수만 탐색하게 만들고 싶다고 하자. 이 경우, 전달 함수(forwarding function) 을 만들어 주면 이 문제를 간단히 해결할 수 있다.

/*
그렇다면 이제 한 걸음 더 나아가보자. int 인자를 받는 mf1 함수와 인자를 받지 않는 mf1 함수가 Base 클래스에 정의되어 있고, Derived 클래스는 mf1 을 찾을 때 인자를 받지 않는 mf1 함수만 탐색하게 만들고 싶다고 하자. 이 경우, 전달 함수(forwarding function) 을 만들어 주면 이 문제를 간단히 해결할 수 있다.

class Base
{
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int);
	...
};

class Derived: private Base
{
public:
	// 암시적으로 인라인 함수가 됨
	virtual void mf1()   //이렇게 안에 숨기면 됨
	{
		Base::mf1();
	}
};


*/
int main () {
Derived d;
int x;

    d.mf1(); // Derived::mf1 호출
    d.mf1(x); // 에러! Derived::mf1 이 Base::mf1 을 가림

    d.mf2(); // Base::mf2() 호출

    d.mf3(); // Derived::mf3 호출
    d.mf3(x); // 에러! Derived::mf3 이 Base::mf3 을 가림

}