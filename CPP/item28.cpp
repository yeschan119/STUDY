#include <iostream>

//객체에 대한 핸들을 반환하는 코드는 조심
class Point
{
    public:
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }

        void setX(int new_x){
            x = new_x;
        }

        void setY(int new_y){
            y = new_y;
        }

    private:
        int x;
        int y;
};

struct RectDate
{
    Point ulhc;
    Point lrhc;
};

class Rectangle
{
    public:
        Rectangle(Point& p1, Point&p2)
        {

        }
        Point& upperleft() const {return pData->ulhc;}  // Point 앞에 const 넣어주면 해결
        Point& lowerright() const {return pData->lrhc;}
    private:
        std::shared_ptr<RectDate> pData;
};

int main()
{
    Point coord1(0,0);
    Point coord2(100, 100);

    const Rectangle rec(coord1, coord2);

    //이렇게 내부 데이터를 마음대로 바꿀 수 있음
    rec.upperleft().setX(50);

}