#include <iostream>

void some_func(int& a)
{
    a = 8;
}

int main()
{
    int a = 5;
    std::cout << a;
    some_func(a);
    std::cout << a;

    return 0;
}