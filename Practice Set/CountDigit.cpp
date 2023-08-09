#include <iostream>
using namespace std;

int main()
{
    string s = "7934s232c";
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            count++;
        }
    }
    cout << count;
    return 0;
}