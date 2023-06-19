#include <iostream>

//파일 사이의 컴파일 의존성을 최대로 줄이자.

//아래와 같은 코드를 컴파일하기 위해서는 string, date, address 클래스의 구현 세부사항을 알고 있어야 한다.
//즉, 수많은 #include가 필요하다는 뜻이다.
//파일 하나만 바뀌어도 해당 파일을 사용하는 모든 파일을 다시 컴파일 해야 하는 것.

class Person
{
public:
    Person(const std::string& name, const Date& birthday,
        const Address& addr)
    {
    std::string name() const;
    std::string birthDate() const;
    std::string address() const;
    }
private:
    std::string theName;
    Date theBirthDate;
    Address theAddress;
};

//아래와 같은 방법으로 pimpl관용구 기법으로 해결할 수 있다.
class PersonImpl;
class Date;
class Address;

class Person
{
public:
    Person(const std::string& name, const Date& birthday,
        const Address& addr)
        {}
    std::string name() const;
    std::string birthDate() const;
    std::string address() const;
private:
    std::shared_ptr<PersonImpl> pImpl;
};