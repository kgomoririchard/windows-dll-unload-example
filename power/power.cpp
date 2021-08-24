#include <iostream>
#include <chrono>
#include <thread>

#include "power.h"


class Writer
{
public:
    Writer(int i) { std::cout << "Writer ctor" << std::endl; this->i = i; }
    ~Writer() { std::cout << "Writer dtor" << std::endl; }
    int get() { return i; }
    void set(int i) { this->i = i; }

private:
    int i;
};

std::thread* WorkerThread;

void proc()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "DLL: I'm alive" << std::endl;
    }
}

inline void __cdecl function()
{
    static Writer w(1);
    std::cout << "i=" << w.get() << std::endl;
    w.set(w.get() + 1);

    if (WorkerThread == nullptr)
    {
        WorkerThread = new std::thread(proc);
    }
}

/*
int __cdecl power(int base, int exp)
{
    function();

    int res = 1;
    for (int idx = 1; idx <= exp; ++idx)
    {
        res *= base;
    }
    return res;
}
*/

