#include <iostream>
/*가상함수가 하나라도 들어 있는 base class의 distructor는 꼭 virtual 선언
안 그러면 delete가 진행되지 않아 memory leak이 발생*/

class TimeKeeper {
    public:
        TimeKeeper(){std::cout << "TimeKeeper constructor" << std::endl;}
        virtual ~TimeKeeper(){std::cout << "TimeKeeper distructor" << std::endl;}

        virtual void getTimeKeeper(){std::cout << "Base Time Keeper" << std::endl;}
};

class AtomicClock : public TimeKeeper {
    void getTimeKeeper(){std::cout << "Atomic Time Keeper" << std::endl;}
};
class WaterClock : public TimeKeeper{
    void getTimeKeeper(){std::cout << "Water Time Keeper" << std::endl;}
};
class WristClock : public TimeKeeper{
    void getTimeKeeper(){std::cout << "Wrist Time Keeper" << std::endl;}
};

TimeKeeper * test() {
    TimeKeeper * derived_obj = new AtomicClock();

    return derived_obj;
}

int main () {
    TimeKeeper *ptk = test();
    delete ptk;
    std::cout << "item7 is done" << std::endl;
    return 0;
}