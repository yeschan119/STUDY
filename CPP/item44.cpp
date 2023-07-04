#include <iostream>

//매개변수에 독립적인 코드는 템플릿으로부터 분리시키자
//아래 invert함수가 template 매개변수와 관련이 없는 함수
//template을 사용하면 비슷비슷한 클래스와 함수가 여러 개 만들어지는데, 템플릿 매개변수에 종속되지 않은 코드는, 코드를 비대하게 만든다.
template<typename T>
class SqueareMatrixBase
{
    protected:
        SqueareMatrixBase(std::size_t n, T *pMem)
        :size(n), pData(pMem) {}
        void intert(std::size_t matrixSize);
    private:
        std::size_t size;
        T *pData;
};

template<typename T, std::size_t n>
class SquareMatrix : private SqueareMatrixBase<T>
{
    private:
        //using SqueareMatrixBase<T>::invert;
        T data[n * n];
        //boost::scoped_array<T> pData;  //new[]처럼 동작하지만 스마트 포인터처럼 영역에서 빠져나갈 때 자동으로 메모리 해제
    public:
        SquareMatrix()
        :SqueareMatrixBase<T>(n, data) {}
        void invert() {
            this->intert(n);  //이렇게 하면 base class의 invert함수가 한번 호출되고, 다음에 호출될 때마다 사본이 만들어진다.
        }
};

int main ()
{
    SquareMatrix<double, 5> sm1;
    sm1.invert();

    SquareMatrix<double, 10> sm2;
    sm2.invert();
    //완전히 같은 동작을 두번 수행해도 invert 함수를 중복해서 생성한다.
}