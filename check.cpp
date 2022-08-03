#include <bits/stdc++.h>
using namespace std;
vector<int> getCumulativeSum(vector<int> &arr)
{
    // add your logic here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i);
    }
    for (int j = 1; j < n; j++)
    {
        arr[j] = arr[j] + arr[j - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        vector<int>arr;
        getCumulativeSum(arr);
    }
    return 0;
}