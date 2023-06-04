#include <iostream>

//class 설계는 type 설게이다. 새로운 타입을 정의하기 전에, 아래 항목에 나온 모든 고려사항을 체크
int main()
{
    std::cout << "1. 새로 정의한 타입의 객체 생성 및 소멸은 어떻게 이루어 져야 하는가?(operator new, operator delete[] ...)" << std::endl;
    std::cout << "2. 객체 초기화는 객체 대입과 어떻게 달라야 하는가?" << std::endl;
    std::cout << "3. 새로운 타입으로 만든 객체가 값에 의해 전달되는 경우에 어떤 의미를 줄 것인가?(복사 생성자)" << std::endl;
    std::cout << "4. 새로운 타입이 가질 수 있는 적법한 값에 대한 제약은 무엇으로 잡을 것인가?(유리수, 분모가 0 안됨 ..)" << std::endl;
    std::cout << "5. 기존의 클래스 상속 계통망(inheritance graph)에 맞출 것인가?(상속 및 가장/비가상 함수)"  << std::endl;
    std::cout << "6. 어떤 종류의 타입 변환을 허용할 것인가?(명시적/암시적 변환 등)" << std::endl;
    std::cout << "7. 어떤 연산자와 함수를 두어야 의미가 있을까?" << std::endl;
    std::cout << "8. 표준 함수들 중 어떤 것을 허용하지 말 것인가?(private으로 선언, uncopyable등)" << std::endl;
    std::cout << "9. 새로운 타입의 멤버에 대한 접근 권한을 어느 쪽에 줄 것인가?(접근 지정자 및 friend class)" << std::endl;
    std::cout <<"10. 선언되지 않은 인터페이스로 무엇을 둘 것인가?" << std::endl;
    std::cout <<"11. 새로 만드는 타입이 얼마나 일반적인가?(템플릿이 필요한지)" << std::endl;
    std::cout <<"12. 정말 필요한 타입인가?" << std::endl;
}