#include <iostream>

template<typename T> class Widget;
template<class T> class Widget2;

//typename과 class는 차이가 없음
//굳이 차이를 찾자면 typename이 중첩의존이름을 식별하는데 쓰인다는 거?
//const_iterator처럼 탬플릿 매개변수에 종속되어 들어오는 타입에 따라 연산 타입이 결정되는 경우를 의존 이름(dependent name)이라고 한다.
//아래처럼 const_iterator가 C라는 클래스에 종소되어 있는 경우를 중첩 의존 타입 이름(nested dependent type name)이라고 한다.
template<typename C>

void print2nd(const C& container)
{
    if (container.size() >= 2)
    {
        C::const_iterator iter(container.begin());
        typename C::const_iterator * x;  //이는 const_iterator타입의 포틴터 x를 선언한 것이지만 만일 C클래스에 const_iterator라는 변수가 있는 경우
        //곱하기 연산으로 취급될 것이다. 이런 것을 해결하기 위해 앞에 typename을 붙여준다.

        ++iter;
        int value = *iter;
        std::cout << value;
    }
}

template<typename T>
//이렇게 Base class list인 경우 앞에 Typename을 주면 안됨.
class Derived: public Base<T>::Nested
{
    public:
        //멤버 초기화 리스트에 있는 base class 식별자에 typname을 붙이면 안됨
        explicit Derived(int x)
        : Base<T>::Nested(x);
    {
        typename Base<T>::Nested temp;
    }
};

//typename std::iterator_traits<IterT>::value_type 은 풀어 설명하면 "IterT 타입의 객체로 가리키는 대상의 타입" 이라는 뜻이다.
//즉, iter 의 타입이 vector<int>::iterator 라면, temp 는 int 타입이 될 것이다.

template<typename IterT>
void workWithIteragot(IterT iter)
{
	typename std::iterator_traits<IterT>::value_type temp(*iter);
}

//typename std::iterator_traits<IterT>::value_type 은 다음과 같이 간략화가 가능한데, typedef 이름을 만들 때는 그 멤버 이름과 똑같이 짓는 것이 관례이다
template<typename IterT>
void workWithIteragot2(IterT iter)
{
	typedef typename std::iterator_traits<IterT>::value_type value_type;
	value_type temp(*iter);
}