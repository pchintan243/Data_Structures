#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "yu27u";
    string t = "7uu6y";

    int n1 = s.length();
    int n2 = t.length();

    if (n1 != n2)
    {
        return -1;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "anagram";
    }
    else
    {
        cout << "not anagram";
    }
    return 0;
}