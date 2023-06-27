#include <iostream>

class Airport {};

class Airplane
{
    public:
        virtual void fly(const Airport& destination) = 0;
    protected:
        void defaultFly(const Airport& destination) {}
};

class ModelA : public Airplane
{
    public:
        virtual void fly(const Airport& destination)
        {
            defaultFly(destination);
        }
};

class ModelB : public Airplane
{
    public:
        virtual void fly(const Airport& destination)
        {
            defaultFly(destination);
        }
};

class ModelC : public Airplane
{
    public:
	virtual void fly(const Airport& destination)
	{
		// Do something else...
	}
};

//아니면 순수 가상 함수로 해결할 수 있다.
/*
class Airport {};

class Airplane
{
public:
	virtual void fly(const Airport& destination) = 0;
};

void Airplane::fly(const Airport& destination)
{
	// 기본 fly 동작
}

class ModelA: public Airplane 
{
public:
	virtual void fly(const Airport& destination)
	{
		Airplane::fly(destination);
	}
};
class ModelB: public Airplane 
{
	public:
	virtual void fly(const Airport& destination)
	{
		Airplane::fly(destination);
	}
};
class ModelC: public Airplane 
{
	public:
	virtual void fly(const Airport& destination)
	{
		// Do something else...
	}
};
*/