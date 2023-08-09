#include <iostream>
using namespace std;

int main()
{
    string s = "7uuyf  uy";
    int a[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (a[i] == 1)
        {
            cout << char(i) << ":" << a[i] << " ";
        }
    }
    return 0;
}