#include <iostream>

//template으로 만들어진 기본 클래스 안의 이름에 접근하는 방법을 알아 두자
class CompanyA
{
    public:
        void sendCleartext(const std::string& msg);
        void sendEncrypted(const std::string& msg);
};

class CompanyB
{
    public:
        void sendCleartext(const std::string& msg);
        void sendEncrypted(const std::string& msg);
};

class CompanyC
{
    public:
        void sendCleartext(const std::string& msg);
        void sendEncrypted(const std::string& msg);
};

class MsgInfo {};

template<typename Company>
class MsgSender
{
    public:
        void sendClear(const MsgInfo& info)
        {
            std::string msg;

            Company c;
            c.sendCleartext(msg);
        }

        void sendSecret(const MsgInfo& info)
        {
            std::string msg;

            Company c;
            c.sendEncrypted(msg);
        }
};

template<typename Company>
class LoggingMsgSender: public MsgSender<Company>
{
    public:
        using MsgSender<Company>::sendClear;  //2.using을 사용하는 방법도 있음. 컴파일러에게 sendClear 함수가 기본 클래스에 있다고 가정하라고 알려준다.
        void sendClearMsg(const MsgInfo& info)
        {
            sendClear(info);   //compile 안됨. Company가 정확이 무엇인지 모르는 상황에서 MsgSender<Company> 클래스가 어떤 형태인지 알수 없기 때문
            this->sendClear(into);  // 1.this를 사용하면 된다.
            MsgSender<Company>::sendClear(info);  //3.호출할 함수가 기본 클래스의 함수라는 점을 명시적으로 지정. 그러나 이 방식은 함수가 가상함수의 경우 가상함수 바인딩이 무시될 수 있어서 노추천.
        }
};

int main()
{
    MsgSender<CompanyA> msg;
}