#include <iostream>

class Base {};
class Derived: public Base {};

template<typename T>
class SmartPtr
{
    public:
        template<typename U>
        SmartPtr(const SmartPtr<U>& realPtr)  //이렇게 멤버 함수 탬플릿을 사용해야 원하는 복사 생성자가 만들어짐
        : heldPtr(realPtr.get()) {}   // 이렇게 해야 불필요한 업캐스팅이 일어나지 않는다.
        T *get() const {return heldPtr;}
    private:
        T *heldPtr;
};

//compiler는 나름의 복사생성자를 만들기 때문에 일반화 복사 생성자와 그냥 복사 생성자를 잘 써야 한다.

template <class T> class Shared_Ptr
{
    public:
        Shared_Ptr(Shared_Ptr) const& r);  //복사 생성자

        template<class Y>
        explicit Shared_Ptr(Shared_Ptr<Y> const& r); //일반화 복사 생성자

        Shared_Ptr& operator=(Shared_Ptr const& r);

        template<class Y>
        Shared_Ptr& operator=(Shared_Ptr<Y> const& r);  //일반화 복사 대입 연산자
};

int main() 
{
    Base *pt1 = new Derived;   // 이건 허용되지만 아래는 허용 안됨
    SmartPtr<Base> pt1 = SmartPtr<Derived>(new Derived);  //컴파일러 입장에서 두 객체는 완전히 별개의 수준이다.

}