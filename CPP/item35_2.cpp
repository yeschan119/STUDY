#include <iostream>>

// 이 방법 역시 가상 함수 대신 쓸수 있는 비가상 방법이다.
// "고전적인" 전략 패턴이며, 체력치 계산 함수를 나타내는 클래스 계통을 아예 따로 만든다.
class GameCharacter;

class HealthCalcFunc
{
    public:
        virtual int calc(const GameCharacter &gc) const {
            return 10;
        }
};

HealthCalcFunc defaultHealthCalc;

class GameCharacter
{
    public:
        explicit GameCharacter(HealthCalcFunc *phcf = &defaultHealthCalc)
        : pHealthFunc(phcf) {}

        int healthValue() const
        {
            return pHealthFunc->calc(*this);
        }

    private:
        HealthCalcFunc *pHealthFunc;
};