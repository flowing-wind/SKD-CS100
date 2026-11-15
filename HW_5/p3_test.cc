#include "p3.cc"
#include <iostream>

int main()
{
    int raw[] = {1, 2, 3};

    Dynarray a(raw, raw + 3);
    Dynarray b = a;

    b[1] = 9;

    std::cout << a << '\n';
    std::cout << b << '\n';

    std::cout << (a == b) << '\n';
    std::cout << (a < b) << '\n';

    Dynarray empty;
    std::cout << empty << '\n';
}