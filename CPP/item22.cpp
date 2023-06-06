#include <iostream>
#include <string>

//데이터가 선언될 곳은 반드시 private 영역으로
//protected는 public보다 많이 '보호'받고 있는 것이 절대로 아니다.

int main()
{
    //private을 쓰면
    std::cout << "1. 문법적 일관성(콤마를 붙여야 하는지, 괄호를 붙여야 하는지 헷갈리지 않음)" << std::endl;
    std::cout << "2. 데이터 멤버의 접근성을 세밀하게 제어할 수 있음" << std::endl;
    std::cout << "3. 캡슐화(encapsulation)" << std::endl;

    //protected 일 경우
    //protected의 데이터 멤버를 제거할 경우 파생 클래스까지 다 살펴보아야 하므로 public과 다를 게 없이 귀찮.
}