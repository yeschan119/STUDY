#include <iostream>

//객체지향 프로그램은 명시적 인터페이스와 런타임 다형성이 핵심이다?

class Widget
{
    public:
        virtual int normalize();
        void swap(Widget& other);
};

//doProcessing에서 w는 Widget타입이므로 w는 Widget의 인터페이스를 지원한다. 이 인터페이스들은 소스코드에서
//어떤 형태인지 확인 가능하므로 이런 인터페이스를 명시적 인터페이스(explicit interface)라고 한다.
//widget의 멤버들 중 가상 함수는 런타임에 호출될지 말지 결정되므로 런타임 다형성(runtime polymorphism)이라고 함.
void doProcessing(Widget &w)
{
    Widget temp(w);
    int a = temp.normalize();
    temp.swap(w);
}

//반면 template은 암시적 인터페이스(implicit interface)와 컴파일 타임 다형성(compile-time polymorphism)이 중요
//T가 normalize와 swap을 지원하는지 확실하지 않지만 지원해야 제대로 컴파일이 이루어 진다. 이를 implicit interface라고 한다.
template <typename T>
void doProcessing2(T &w)
{
    T temp(w);
    int a = temp.normalize();
    temp.swap(w);
}

//위 함수들의 호출을 성공시키기 위해 템플릿의 인스턴스화가 컴파일 도중에 일어나는데 어떤 템플릿 매개변수가 들어가느냐에 따라
//호출되는 함수가 달라지기 때문에 이를 compile polymorphism이라고 한다.