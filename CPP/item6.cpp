#include <iostream>
/*
copy assignment, copy constructor
두 연산자는 필요할 때, 즉 생성하지 않았는데, 누군가 요청하면 알아서 만들어진다.
HomeForSale에서 각각의 집은 유일안 유닛으로 만드는 것이 조건이라 일부러 위 메소드들을 만들지 않았는데,
유저가 요청하면 자동으로 생성되므로 이것을 막아야 HomeForSale 클래스의 조건을 만족하게 된다.
*/

class UnCopyable {
    protected:
        UnCopyable() {}
        ~UnCopyable() {}
    private:
        UnCopyable(const UnCopyable&);
        UnCopyable operator = (const UnCopyable&);
};

class HomeForSale : private UnCopyable {
    char *Address;
    int price;
    /*
    private:
        복사연산자와 대입연산자를 private 공간에 넣어, 이 작업을 밖에서 요청 못하도록 함(link error)
        이렇게 할 경우 에러 발생 시점이 link 시점인데 이를 컴파일러 시점으로 옮길 수 있음.
        
        HomeForSale(const HomeForSale&);
        HomeForSale &operator = (const HomeForSale&);
    */
};

int main(){
    HomeForSale h1;
    HomeForSale h2;

    //HomeForSale h3(h1);  //복사 연산을 할 수 없도록...
    //h1 = h2;  //대입 연산을 할 수 없도록..

    std::cout<<"item6 has done."<<std::endl;

    return 0;
}