#include <iostream>

//has a 혹은 is-implemented-in-terms-of 형태는 객체 합성을 사용하자
//객체합성(object composition)의 의미는 public 상속이 가진 의미와 완전히 다르다.
//응용 영역에서 객체 합성의 의미는 "has a" 이다. 구현 영역에서 is-implemented-in-terms-of의 의미를 갖는다.

class Address {};
class PhoneNumber {};

class Person
{
    public:
    private:
        std::string name;
        Address address;
        PhoneNumber phonenumber;
};

int main ()
{
    std::cout << "compisition : 어떤 타입의 객체들이 다른 타입의 객체들을 포함하고 있는 경우에 성립하는 타입들 사이의 관계를 말한다." << std::endl;
}