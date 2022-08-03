#include <iostream>

using namespace std;
int printSpell(string str[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        printSpell(str, n / 10);
        cout << str[n % 10] << " ";
    }
}
int main()
{
    string str[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cout << "Enter the number:\n";
    cin >> n;
    printSpell(str, n);
    return 0;
}