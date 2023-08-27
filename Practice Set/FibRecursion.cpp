#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int i = 0;
    int n = 8;
    while (n != i)
    {
        cout << fib(i) << " ";
        i++;
    }

    return 0;
}