#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n) S.C = o(1)
public:
  int findMaxSum(vector<int> &arr)
  {
    int n = arr.size();

    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
      int pick = arr[i] + prev2;
      int not_pick = 0 + prev1;
      int curr = max(pick, not_pick);

      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }
};

class Solution
{ // T.C = o(n) S.C = o(n)
public:
  int findMaxSum(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> dp(n, -1);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
      int pick = arr[i] + dp[i - 2];
      int not_pick = 0 + dp[i - 1];
      dp[i] = max(pick, not_pick);
    }

    return dp[n - 1];
  }
};

class Solution
{ // T.C = o(n) S.C = o(n) + o(n) ~ o(n)
private:
  int max_sum(vector<int> &arr, int idx, vector<int> &dp)
  {
    if (idx < 0)
      return 0;
    if (dp[idx] != -1)
      return dp[idx];
    int pick = arr[idx] + max_sum(arr, idx - 2, dp);
    int not_pick = 0 + max_sum(arr, idx - 1, dp);

    return dp[idx] = max(pick, not_pick);
  }

public:
  int findMaxSum(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> dp(n, -1);
    return max_sum(arr, n - 1, dp);
  }
};