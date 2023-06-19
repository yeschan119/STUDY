#include <iostream>

//inline함수는 정확히 알고 이해하자.

//1. 함수 인라인은 작고, 자주 호출되는 함수에 대해서만 하자. 이렇게 하면 디버깅 및 라이브러리의 바이너리 업그레이드가 용이해지고, 자칫 생길 수 있는
//코드 부플림 현상이 최소화되며, 캐시 적중률도 높아지고, 프로그램의 속도가 더 빨라질 수 있음.
//2. 인라인 함수 탬플릿이 헤더 파일에 들어간다는 일반적인 부분만 생각해서 이들을 inine으로 선언하면 안 된다.

//inline은 컴파일러에 대해 '요청'을 하는 것이지 '명령'이 아니다. 즉 inline을 붙이지 않아도 그냥 되는 경우도 있고,
//명시적으로 할 수도 있다는 뜻이다. 복잡한 함수나 가상 함수는 인라인해주지 않는다.
//인라인 함수를 바꾸어주면 다시 컴파일해야 하지만, 일반 함수를 수정하면 링크만 해주면 된다.

class Person
{
    public:
        int get_age(){
            return age;  // 암시적인 inlining. 이 함수는 클래스 정의 내부에서 정의됨.
        }
    public:
        int age;
};

inline void f(){

}

// 생성자와 소멸자도 인라인하기 좋은 함수가 아니다.

class Base
{
private:
    std::string bm1, bm2;
};

class Derived: public Base
{
public:
  // Derived 생성자가 비어 있다
  // 정말 비어 있을까?
    Derived() {}

    //위 derived()함수는 아래와 같이 동작할 것이다.
    /*
    Derived() 
    {
        Base::Base();

    // dm1 생성을 시도
    try { dm1.std::string::string(); }
    // dm1 생성 도중 예외를 던지면?
    // 기본 클래스 부분 소멸 후 예외 전파
    catch (...)
    {
        Base::~Base();
        throw;
    }
    // dm2, dm3 에 대해서도 위와 동일
    */
private:
    std::string dm1, dm2, dm3;
};

//위의 decirved() 함수는 아래와 같이 동작할 것이다.

int main()
{
    void (*ptrf)();

    ptrf = f;

    f();   // 이 함수는 inline 되지만
    ptrf(); // 이 함수는 inline 안된다.
}