#include <bits/stdc++.h>
using namespace std;

int totalSubset = 0;
void printSubset(vector<int> input, vector<int> output, int index)
{
    if (index >= input.size())
    {
        for (auto i : output)
        {
            cout << i << "";
        }
        cout << endl;
        totalSubset++;
        return;
    }
    printSubset(input, output, index + 1);

    output.push_back(input[index]);
    printSubset(input, output, index + 1);
}
int main()
{
    int size;
    cout << "Enter size:" << endl;
    cin >> size;

    vector<int> vec(size);
    vector<int> subset;

    cout << "Enter elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
    cout << "Power set is as follows:" << endl;
    printSubset(vec, subset, 0);
    cout << "Total number of subset is:" << totalSubset << endl;
    return 0;
}