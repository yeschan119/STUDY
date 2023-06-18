#include <iostream>

// 변수 정의는 늦출 수 있는 데까지 늦추는 근성 발휘

int dummy_func()
{
    //...
    return 0;
}

// 생성 후 값을 대입하지 말고 생성과 동시에 초기화를 하면 쓸데없는 기본 생성자 호출 비용을 줄일 수 있음
std::string encryptedPassword(const std::string& password)
{
    using namespace std;
    string encrypted;
    int dummy = dummy_func(); //여기서 에러가 발생하면 encrypted 변수 선언은 의미가 없다.

    encrypted.assign("passward");

    return encrypted;
}

int main()
{
    std::string input_pw("12345");
    std::string output_pw = encryptedPassword(input_pw);

    std::cout << output_pw << std::endl;
}