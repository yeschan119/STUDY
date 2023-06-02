#include <iostream>
#include <string>
// new로 생성한 객체를 스마트 포인터로 넣는 코드는 별도의 문장으로 만들자
// 안그러면 예외 발생시 디버깅하기 힘든 자원 누출이 초래
int priority()
{
    return 1;
}

class Widget
{
    private:
        int member;
    public:
        Widget(){member = 0;}
        Widget(int m) :member(m){}
        void print_widget();
};

void Widget::print_widget()
{
    std::cout << member << std::endl;
}

/* 이런 복사 생성자를 또 만들면 EXC_BAD_ACCESS (code=1, address=0x0) 이러 에러가 생김(대충 중복 사용이라는 것)
void Widget::set_widget(const int m)
{
    try {
        member = m;
    }
    catch(std::exception &e)
    {
        std::cout << typeid(e).name() << std::endl;
        std::cerr << e.what() << std::endl;
    }
}
*/

class WidgetQueue
{
    private:
        int priority;
        std::shared_ptr<Widget> wgd;
    public:
        WidgetQueue(std::shared_ptr<Widget> wg, int pr)
        {
            wgd = wg;
            priority = pr;
        }
};

int main()
{
    //WidgetQueue wdg1(new Widget, priority()); compile error, shared_ptr이 explicit이기 때문에 new Widget
    // 으로 만들어진 포인터가 share_ptr 타입으로 형변환이 일어나지 않음

    WidgetQueue wdg(std::shared_ptr<Widget>(new Widget), priority());
    //이것도 위험.. new widget 실행하고 중간에 priority를 먼저 처리하다 에러 발생하면 끝
    // 두 개 인자중 어떤 걸 먼저 처리하는지 모름. new widget, shared_ptr, priority 항상 이렇게 처리하지 않음

    std::shared_ptr<Widget> wdg2(new Widget(300));
    std::shared_ptr<Widget> wdg3;   // 이렇게 하면 런타입시 seg fault 남,, 초기화가 안되었기때문
    Widget * wdg4;   // 이것도 마찬가지

    //wdg2->set_widget(100);
    //wdg4->print_widget(300)   // 여기서 segment fault 

    wdg2->print_widget();

    delete wdg4;

}