#include <iostream>

//예외 안정성 확보
//예외 안전성은 아래 세가지를 보장
//기본적인 보장(basic garantee) 함수 동작 중에 예외가 발생하면 실행 중인 프로그램에 관련된 모든 것들을 유효한 상태로 유지.
//강력한 보장(strong guarantee) 함수가 성공적으로 실행을 마친 후의 상태와 함수가 호출될 때의 상태만이 존재할 수 있다.
//예외불가 보장(nothrow guarantee) 예외를 던지지 않겠다는 보장. 약속한 동작은 언제나 끝까지 완수하는 함수라는 뜻.

class Mutex
{
    public:
        Mutex(){}
};

class Image
{
    public:
        void showImage();
};

class PrettyMenu
{
    public:
        // 배경 그림을 바꾸는 멤버 함수
        void changeBackground(std::istream* imgSrc);
    private:
        Mutex mutex;
        Image *bgImage; // 현재의 배경 그림
        int imgaeChanges; // 배경 그림이 바뀐 횟수
};

void PrettyMenu::changeBackground(std::istream& imgSrc)
{
    //lock(&mutex);
    
    delete bgImage;
    ++imgaeChanges;
    //bgImage = new Image(imgSrc);   //여기에 예외가 발생한다면 자원이 새고 자료구조가 더럽혀진다.
    // lock이 안풀리고, image는 이미 지워진 상태가 된다. 복구가 안됨
    //unlock(&mutex);

    // 아래와 같이 바꿀 수 있다.
    // Lock m1(&mutex);
    // bgImage.reset(new Image(imgSrc));  //bgImage의 내부 포인터를 new image의 표현식의 실행 결과로 바꿔치기
    // ++imageChanges;
}