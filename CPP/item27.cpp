#include <iostream>

//casting은 웬만하면 피하자. 특히 dynamic_cast는 신중. 수행성능에 안좋음.
//어쩔수 없이 해야 하면 함수 안에 숨긴다?
//꼭 해야 하면 구형이 아닌 C++ 스타일 선호
//구형은 T(exp)
//C++ style은
//const_cast : 객체의 상수성(constness)를 없애는 용도로 사용
//dynamic_cast : 안전한 다운캐스팅(safe downcasting)을 할 때 사용함. 런타임 비용이 높다.
//reinterpret_cast : 포인터를 int로 바꾸는 등의 하부 수준 캐스팅을 위해 만들어진 연산자로, 적용 결과가 구현환경에 의존적.
//static_cast : 암시적 변환(비상수 객체를 상수 객체로, 혹은 int를 double로 등)을 강제로 진행할 때 사용.
//              타입 변환을 거꾸로 수행하는 용도로도 쓰임.(void *를 일반 타입의 포인터로)

class Widget
{
    public:
        explicit Widget(int size);
};

void doSomeWork(const Widget& w){
    std::cout<<"do some work" << std::endl;
}

class Window
{
    public:
        virtual void oneResize() {}

};

class SpecialWindow: public Window
{
    public:
        virtual void oneResize()
        {
            static_cast<Window>(*this).oneResize();  // 이렇게 하면 캐스팅이 안됨. this의 사본을 호출하게 됨.
            Window::oneResize();   // 이렇게 해야 제대로 window를 호출하는 것임
        }
        void blink();
};

typedef std::vector<std::shared_ptr<Window>> VPW;
typedef std::vector<std::shared_ptr<SpecialWindow>> VPSW;

int main () {
    // int로 widget 생성 구형 방식
    doSomeWork(Widget(15));
    // c++ 방식, int로부터 widget 생성
    doSomeWork(static_cast<Widget>(15));

    // dynamic cast는 비용이 매우 큰 캐스팅으로 필요한 경우에만 구현.
    VPW windPtrs;
    VPSW windPtrs2;
    
    for (VPW::iterator iter = windPtrs.begin(); iter != windPtrs.end(); ++iter)
    {
        // 아주 고비용을 dynamic_cast 사용중
        if (SpecialWindow *psw = dynamic_cast<SpecialWindow*>(iter->get()))
            psw->blink();
    }

    for (VPSW::iterator iter = windPtrs2.begin(); iter != windPtrs.end(); ++iter)
    {
        // 위 for문을 이랗게 바꾸면 성능 해결
        (*iter)->blink();
    }
    
}