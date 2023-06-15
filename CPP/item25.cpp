#include <iostream>

//예외를 던지지 않는 swap에 대한 지원
//std::swap이 사용자 정의 타입에 대해 느리게 동작할 여지가 있다면 swap멤버 함수 제공
//std::swap의 경우 복사생성자와 복사대입 연산자를 호출하므로 느리다.

class WidgetImpl
{
    private:
        int a, b, c;
        std::vector<double> v;
};

class Widget
{
    public:
        void swap(Widget& other)
        {
            using std::swap;
            swap(pImpl, other.pImpl);
        }
        Widget(const Widget& rhs);

        Widget& operator=(const Widget& rhs)
        {
            *pImpl = *(rhs.pImpl);
        }
    private:
        WidgetImpl *pImpl;
};

int main() {

}