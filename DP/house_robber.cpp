#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n) S.C = o(1)
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
      int take = nums[i] + prev2;
      int non_take = 0 + prev1;
      int curr = max(take, non_take);
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }
};

class Solution
{ // T.C = o(n)  S.C = o(n)
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp(n, -1);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
      int take = nums[i] + dp[i - 2];
      int non_take = 0 + dp[i - 1];
      dp[i] = max(take, non_take);
    }

    return dp[n - 1];
  }
};

class Solution
{ // T.C = o(n) S.C = o(n) + o(n)-> for stack space
private:
  int max_amount(int n, vector<int> &nums, vector<int> &dp)
  {
    if (n == 0)
      return nums[n];
    if (n == 1)
      return max(nums[n], nums[n - 1]);

    if (dp[n] != -1)
      return dp[n];

    int take = nums[n] + max_amount(n - 2, nums, dp);
    int non_take = 0 + max_amount(n - 1, nums, dp);
    return dp[n] = max(take, non_take);
  }

public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return max_amount(n - 1, nums, dp);
  }
};