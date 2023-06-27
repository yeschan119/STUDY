#include <iostream>

//상속 받은 비가상함수를 파생 클래스에서 재정의하는 짓은 멈춰!!
//비가상함수를 상속 받는다는 것이 기반 클래스의 인터페이스와 구현을 모두 물려받는다는 뜻이므로 파생클래스에서 재정의 하다는 게
//이론적으로도 모순
class B
{
    public:
        void mf() { std::cout << "B" << std::endl;}
};

class D : public B
{
    public:
        void mf() { std::cout << "D" << std::endl;}
};

//비가상함수는 static binding으로 묶여 있어서 생성시점의 포인터 타입에 맞는 함수가 호출
//가상함수는 dynamic binding으로 묶여 있어서 그때 그때 가리키는 타입의 객체의 함수가 호출
//static binding은 빌드 중에 타입이 정해지고, dynamic binding은 런타임에 정해진다.
//C++은 런타임 성능을 높이기 위해 가상함수를 static binding으로 수행. 컴파일 중에 가상 함수 테이블을 파생 클래스에 맞게 바꿈으로써
//겉보기에는 파생 클래스 타입에서 오버라이드한 가상 함수를 호출하는 것처럼 보임.
int main ()
{
    D x;
    B *pb = &x;
    pb->mf();  //D를 가리키지만 B로 생성되었기 때문에 B가 출력

    D *pD = &x;
    pD->mf();  // D가 출력
}