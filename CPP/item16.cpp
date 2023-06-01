#include <iostream>
#include <string>

typedef std::string AddressLines[10];

int main ()
{
    std::string *pal_arr = new AddressLines;
    std::string *pal = new std::string("delete");
    
    delete pal_arr; // array를 그냥 ptr로 처리하려다 동작을 멈추어서 미정의 동작이 됨 
    delete []pal;  // 앞쪽 메모리를 읽고 이것을 배열의 크기라고 착각하고 그 값만큼 delete 진행

    return 0;
}