#include <iostream>
#include <string>

class Mutex {
    public:
        int res;
};

class Lock
{
    public:
        explicit Lock(Mutex *pm)
        : MutexPtr(pm)
        {lock(MutexPtr);}

        void lock(Mutex *ptr) {
            if (ptr == NULL)
                std::cout << "Lock is failed" << std::endl;
            else
                std::cout << "Lock is succeeded" << std::endl;
        }

        void unlock(Mutex *ptr) {
            delete ptr;
            std::cout << "unlock" << std::endl;
        }

        ~Lock() {unlock(MutexPtr);}

    private:
        Mutex * MutexPtr;
};

int mina()
{
    Mutex *m;
    std::shared_ptr <Mutex> m2;
    Lock lck(m);
    lck.lock(m);

    return 0;
}