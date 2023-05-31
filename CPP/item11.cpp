#include <iostream>
#include <string>
//자기 자신을 대입할 경우 에러가 발생할 수 있으므로 잘 처리해주자
class Bitmap
{
    public:
        int bitmap;
};

class Widget
{
    private:
        Bitmap* pb;
    public:
        Widget &operator=(const Widget &rhs);
};

Widget& Widget::operator=(const Widget& rhs)
{
    try {
        Bitmap * org = pb;
        pb = new Bitmap(*rhs.pb);
        delete org;
    }
    catch (std::exception &e)
    {
        std::cout << typeid(e).name() << std::endl;
        std::cerr << e.what() << std::endl;
    }

    return *this;
}

int main ()
{
    Widget w1;
    w1 = w1;
    return 0;
}