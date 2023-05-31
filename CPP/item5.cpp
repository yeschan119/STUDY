#include <iostream>
#include <vector>
#include <string>
// compiler가 은근 슬쩍 만드는 생성자들을 조심
// default, copy, assignment constructor
// 타입 변환이나 참조자, const등을 고려하지 않으므로...
template <typename T>
class NamedObject
{
public:
    NamedObject(std::string &name, const T &value)
        : nameValue(name),
          objectValue(value)
    {
    }

private:
    std::string &nameValue;
    const T objectValue;
};

int main()
{
    std::string newDog("Persephone");
    std::string oldDog("Satch");

    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);

    //p = s;  // default assignement 생성자로 수행되지만 const타입을 변환시키려 하므로 에러 발생

    std::cout<<"end"<<std::endl;

    return 0;
}
