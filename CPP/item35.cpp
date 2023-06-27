#include <iostream>

//가상 함수 대신 쓸 수 있는 것들을 생각해 두자.

class NPCBase
{
    public:
        NPCBase(){}
        virtual ~NPCBase(){}

        //사용자에게 공개되는 인터페이스
        void Action()
        {
            ActionImpl();
        }
    private:
        virtual void ActionImpl() = 0;   //순수가상함수로 만들어서 상속자들이 무조건 정의하도록...
};

class NPCKid : public NPCBase
{
    public:
        NPCKid() {}
        virtual ~NPCKid() {}
    private:
        virtual void ActionImpl()
        {
            std::cout << "아이가 막 뛰어다님" << std::endl;
        }
};

class NPCMerchant : public NPCBase
{
    public:
        NPCMerchant(){}
        virtual ~NPCMerchant(){}
    private:
        virtual void ActionImpl()
        {
            std::cout << "상인은 물건을 팔고 있음" << std::endl;
        }
};

int main()
{
    //NPCBase a;  // 순수 가상함수가 포함된 추상 클래스이므로 인스턴스화는 불가능

    NPCKid kid;
    NPCMerchant merchant;

    // 이런 게 사용자 입장에서는 매우 편리함.
    // 일반 가상함수를 사용할 경우 인터페이스마다 따로따로 virtual 함수를 관리해야 한다. 그럼 단점은??
    kid.Action();
    merchant.Action();
}