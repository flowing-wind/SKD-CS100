#include "p4.cc"
#include <iostream>

struct Widget
{
    int id;

    explicit Widget(int n) : id(n)
    {
        std::cout << "create " << id << '\n';
    }

    ~Widget()
    {
        std::cout << "destroy " << id << '\n';
    }
};

int main()
{
    SharedPtr<Widget> a(new Widget(7));

    {
        SharedPtr<Widget> b = a;
        std::cout << a.use_count() << '\n';
    }

    std::cout << a.use_count() << '\n';
}