#include <iostream>
using namespace std;

int main()
{
    string s = "79s34s23s2c";
    char c = 's';
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}