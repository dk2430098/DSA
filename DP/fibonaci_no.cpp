#include <bits/sdtc++.h>
using namespace std;

int fibo(int n, int *dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));

    cout << fibo(n, dp) << endl;
}