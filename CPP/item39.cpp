#include <iostream>

//private 상속을 굳이 하는 경우는 비공개 멤버로 접근하거나 가상 함수를 재정의할 경우이다.
//is a 관계가 아닌 사이에 상속이 필요한 경우 private으로 상속

class Person {};
class Student: private Person {};

void eat (const Person& p) {}
void stud(const Student &s) {}

class Timer
{
    public:
        explicit Timer(int tickfreq);
        virtual void onTick() const;
    protected:
        int priv_num;
};

void Timer::onTick() const{
    std::cout << "on tick" << std::endl;
}

// Widget 은 Timer 와 is-a 관계가 아니므로,
// public 상속이 아니라 private 상속을 사용함!
class Widget : private Timer
{
    private:
        virtual void onTick() const {
            std::cout << "wedget on tick" << std::endl;
        }
        using Timer::priv_num;
};

//공간 기본 클래스 최적화(empty base optimization)
///C++ 는 "독립 구조(freestanding)의 객체는 반드시 크기가 0을 넘어야 한다" 라는 금기사항이 있다. 예시 코드를 보자.

// 정의된 데이터가 없으므로, 객체는 메모리를 사용하지 않아야 한다
// 하지만 원칙상 최소 1 바이트를 할당해야 한다
// 실제로는 바이트 정렬(alignment) 때문에 padding 을 끼워 넣는다
// 그래서 4바이트 크기 정도로 늘어난다 
class Empty {};

// sizeof(HoldsAnInt) > sizeof(int)
class HoldsAnInt
{
private:
	int x;
	Empty e;
};

// 이러한 금기사항은 private 상속일 경우 적용되지 않음. 즉 empty가 진짜 empty가 된다.
// 다음과 같이 쓰면 sizeof(HoldsAnInt) 가 sizeof(int) 와 같아지게 된다!
// sizeof(HoldsAnInt) == sizeof(int)
class HoldsAnInt : private Empty
{
private:
	int x;
};

int main()
{
    Person p;
    Student s;

    eat(p);
    //eat(s); 에러 발생!!! public 상속과 달리 상속 관계가 private이면 컴파일러는 파생 클래스의 객체를 기본 클래스로 변환하지 않는다.
}