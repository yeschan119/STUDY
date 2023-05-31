#include <iostream>
#include <string>

//복사 생성자를 만들때 모든 멤버 변수를 복사해주도록 하자
//처음 상태에서 새로운 멤버가 추가될 때마다 신경쓰자
// 상속의 경우는 따로
void logCall(const std::string& contents)
{
    std::cout << contents << std::endl; 
}

class Customer
{
    private:
        std::string name;
    public:
        Customer(std::string name)
        : name(name){}
        Customer(const Customer &rhs);
        Customer & operator=(const Customer &rhs);
};

Customer::Customer(const Customer &rhs)
: name(rhs.name)
{
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer &rhs)
{
    logCall("Customer copy assignment operator");
    name = rhs.name;
    return *this;
}

int main()
{
    std::string name("chan");
    Customer c1(name);
    Customer c2(c1);
    Customer c3 = c1;

    return 0;
}