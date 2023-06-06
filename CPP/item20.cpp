#include <iostream>
#include <string>

// pass by value 보다는 pass by reference 방식 선호
// 복사 생성자 호출이 없어 효율적이면서도 slicing problem을 예방
class Window
{
    private:
        std::string name;
    public:
        Window(){name = "C++";}
        std::string name_() const{
            return name;
        }
        virtual void display() const{
            std::cout << name << std::endl;
        }
};

class WindowWithScrollBars: public Window
{
    public:
        virtual void display() const {
            std::cout << Window::name_() << std::endl;
        }
};

//이렇게 하면 pass by value가 되는데, 이는 사본을 만들어 내는 일이고 이 일은 복사 생성자 몫이다.
// 복사 생성자의 실행은 고비용을 요구.
// 또한 복사 손실(slicing problem) 문제가 발생하기도 함
void printNameAndDisplsy(Window w)
{
    std::cout << w.name_() << std::endl;
    w.display();
}

// 아래처럼 참조자에 의한 전달로 하는 것이 좋음
void printNameAndDisplay2(Window &w)
{
    std::cout << w.name_() << std::endl;
    w.display();
}


int main ()
{
    WindowWithScrollBars wwsb;
    printNameAndDisplsy(wwsb);

    printNameAndDisplay2(wwsb);

}