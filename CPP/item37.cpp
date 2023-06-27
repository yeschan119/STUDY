#include <iostream>

//어떤 함수에 대해서도 상속받은 기본 매개변수 값은 절대로 재정의 하지 말자
//이유는 override 함수는 dynamic binding인 반면 그 함수의 매개변수는 static binding 된다.(성능을 위해서)
class Shape
{
    public:
        enum ShapeColor {Red, Green, Blue};
        virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle: public Shape
{
    public:
        virtual void draw(ShapeColor color = Green) const {
            std::cout << color << std::endl;
        }
};

class Circle: public Shape
{
    public:
        virtual void draw(ShapeColor color) const {
            std::cout << color << std::endl;
        }
};

// 아래처럼 하면 가상함수의 기본 매개변수 값을 깔끔하게 받을 수 있다. NVI(non virtual interface) 사용
class Shape2
{
    public:
        enum ShapeColor {Red, Green, Blue};
        void draw(ShapeColor color = Red) const
        {
            doDraw(color);
        }
    private:
        virtual void doDraw(ShapeColor color) const = 0;
};

class Rectangle2 : public Shape2
{
    public:
    private:
        //기본 매개변수 값이 없게 만듬
        virtual void doDraw(ShapeColor color) const {
            std::cout << color << std::endl;
        }
};

int main() {
    //Shape *ps;
    Shape *pc = new Circle;
    Shape *pr = new Rectangle;

    // Rectangle::draw(Shape::Red)를 호출
    // Rectangle::draw(Shape::Green)이 아님
    pr->draw();

    Shape2 *pr2 = new Rectangle2;
    pr2->draw();

}