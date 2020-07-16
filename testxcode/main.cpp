// thread example
#include <iostream>       // std::cout  std::cin
#include <thread>         // std::thread
int a;
void foo()
{
    // do stuff...
    for(int i = 0; i < 100; ++i)
    {
        std::cout << "foo()  i: " << i << "\n";
    }
    a=2;
}
void bar(int x)
{
    // do stuff...
    for(int j = x; j < 200; ++j)
    {
        std::cout << "bar()  j: " << j << "\n";
    }
    a=3;
}
int main()
{
    std::cout << "main, foo and bar now execute concurrently...\n\n";
    a=1;
    std::thread first(foo);     // spawn new thread that calls foo()
    std::thread second(bar, 100);  // spawn new thread that calls bar(0)

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes
    std::cout << "foo and bar completed.\n\n";
    std::cin.get();
    return 0;
}
