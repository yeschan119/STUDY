#include <iostream>
#include <string>
// 인터페이스 설계는 쓰기 쉽게, 오류가 발생하기 어렵게 만들자
// Date class는 잘못 사용될 가능성이 있음. month, day, year 순서를 바꾸어서 입력할 경우..
// factory 함수 처리 잘하자

class Date
{
    public:
        Date(int month, int day, int year)
        :month(month), day(day), year(year){}
    private:
        int month;
        int day;
        int year;
};

// 위 Date class 오류를 아래와 같이 해결

struct Day
{
    explicit Day(int d)
    : val(d) {}

    int val;
};

struct Month
{
    explicit Month(int m)
    : val(m){}

    int val;
};

struct Year
{
    explicit Year(int y)
    : val(y){}

    int val;
};

class Date2
{
    public:
        Date2(const Month& m, const Day& d, const Year& y)
        :month(m.val), day(d.val), year(y.val){}
        Date2(){
            month = 0;
            day = 0;
            year = 0;
        }
        Date2 * create_date();  // 이런 factory 함수의 경우 delete를 깜빡할 수 있으므로 아래와 같은 형식으로 하자!
        std::shared_ptr<Date2> create_date2();
    private:
        int month;
        int day;
        int year;
};

Date2* Date2::create_date()
{
    Date2 *d = new Date2();
    return d;
}

std::shared_ptr<Date2> Date2::create_date2()
{
    std::shared_ptr<Date2> d2(new Date2);
    return d2;
}

int main()
{
    Date d1(30, 10, 2022);
    Date2 d2(Month(5), Day(30), Year(3030));
}