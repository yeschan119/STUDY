#include <iostream>

class Item
{
    public:
        void checkout() {}
};

class Gadget
{
    private:
        void checkout() {}
};

// 아래와 같은 구조에서 가상 상속을 하지 않으면 IOFILE 클래스는 FILE클래스의 경로 갯수 만큼 FILE 객체를 가지게 된다.
class File {};
class InputFile: virtual public File {};
class OutputFile: virtual public File {};

class IOFile : public InputFile, public OutputFile {};

class MP3: public Item, public Gadget {};

int main ()
{
    MP3 mp;

    //mp.checkout();  //error!! 어떤 함수인지 모름

    mp.Item::checkout();  //이렇게 해야 함

    //mp.Gadget::checkout(); //private error
}