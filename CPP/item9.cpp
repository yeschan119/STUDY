#include <iostream>
#include <string>

/*
 * 생성자 및 소멸자 안에서 가장 함수를 호출하지 말자! 가장 함수라고 해도, 지금 실행 중인 생성자나 소멸자에 해당되는 클래스의
 * 파생 클래스 쪽으로는 내려가지 않는다. 즉 virtual 기능이 안됨
 */
class Transaction
{
    public:
        explicit Transaction(const std::string& loginfo);

        void logTransaction(const std::string & loginfo) const {
            std::cout << loginfo << std::endl;
        }
};

Transaction::Transaction(const std::string& loginfo)
{
    logTransaction(loginfo);
}

class BuyTransaction : public Transaction
{
    public:
        BuyTransaction(const std::string& loginfo)
            : Transaction(loginfo){}
};

int main() {
    std::string str ("BuyTransaction Logging");
    BuyTransaction b(str);

    return 0;
}