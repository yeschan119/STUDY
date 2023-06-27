#include <iostream>

//가상 함수 대신 함수 포인터로 구현
//같은 게임 캐릭터에 서로 다른 체력치를 계산
// 전방 선언
class GameCharacter;

// 캐릭터 체력치 계산을 위한 기본 알고리즘 구현	
int defaultHealthCalc(const GameCharacter& gc);

class GameCharacter
{
public:
	typedef int (*HealthCalcFunc)(const GameCharacter&);

	explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc)
	: healthFunc(hcf)
	{}

	int healthValue() const
	{
		return healthFunc(*this);
	}

private:
	HealthCalcFunc healthFunc;
};

class EvilBadGuy: public GameCharacter 
{
public:
	explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc)
	: GameCharacter(hcf)
	{}
};

int loseHealthQuickly(const GameCharacter&);
int loseHealthSlowly(const GameCharacter&);

EvilBadGuy ebg1(loseHealthSlowly);
EvilBadGuy ebg2(loseHealthQuickly);
