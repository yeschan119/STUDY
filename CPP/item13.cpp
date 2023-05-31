#include <iostream>
#include <string>

//자원 누출을 막기 위해 생성자 안에서 자원을 획득하고 소멸자에서 그것을 해제하는 RAII(Resource Acquilsition is initialization) 객체를 사용
//unique_ptr, shared_ptr
//해당 기능은 소멸자로 delete를 사용한다. 따라서 동적으로 할당한 배열에 대해 사용할 수 없다.

class Investment {
    public:
        int x;
};


int main ()
{
    std::unique_ptr<Investment> pnv;
    std::unique_ptr<Investment> pnv2;

    if (pnv == nullptr) std::cout << "pnv is null" << std::endl;

    // pnv = pnv2; 이렇게 쓰면 에러남

    pnv = std::move(pnv2);

    if (pnv2 == nullptr) std::cout << "pnv2 is null" << std::endl;

    std::shared_ptr<Investment> pnv3;
    std::shared_ptr<Investment> pnv4;

    //pnv3 = std::move(pnv4); 이거는 또 에러 안남

    pnv3 = pnv4;

    std::cout << "shared point pnv3" << pnv3.use_count() << std::endl;
    std::cout << "shared point pnv4" << pnv4.use_count() << std::endl;

    std::shared_ptr<int []> sp(new int[10]);   // 배열 할당은 C++17부터 시작

    return 0;
}