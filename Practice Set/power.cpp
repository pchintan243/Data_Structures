#include <iostream>
using namespace std;

// Both function are working same to find the power.
// Only difference is exp is take less time to execute exptwo function is take more time compare to exp function.

int exp(int n) {
    if(n == 0) {
        return 1;
    }
    int answer = exp(n / 2);
    if(n & 1)
    {
        return 2 * answer * answer;
    }
    else {
        return answer * answer;
    }
}
int expTwo(int n){
    if(n == 0){
        return 1;
    }
    int ans = 2 * expTwo(n - 1);
    cout << "for n " << n << " ans " << ans << endl;
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int result = exp(n);
    cout << result;
    return 0;
}