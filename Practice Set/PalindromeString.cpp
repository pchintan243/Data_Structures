#include <iostream>
using namespace std;

int main()
{
    string s = "cahihac";
    bool flag = true;
    for (int i = 0, j = s.length() - 1 - i; i < s.length() / 2; i++, j--)
    {
        if (s[i] != s[j])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "p";
    }
    else
    {
        cout << "n";
    }
    return 0;
}