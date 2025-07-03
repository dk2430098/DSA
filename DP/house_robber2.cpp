#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n) S.C = o(n) -> without dp space
private:
  int solve(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);

    int prev2 = nums[0];
    int prev1 = max(nums[1], nums[0]);

    for (int i = 2; i < n; i++)
    {
      int take = nums[i] + prev2;
      int not_take = 0 + prev1;
      int curr = max(take, not_take);

      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }

public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<int> with_first(nums.begin(), nums.end() - 1); // exclude last
    vector<int> with_last(nums.begin() + 1, nums.end());  // exclude first

    return max(solve(with_first), solve(with_last));
  }
};

class Solution
{ // T.C = o(n) S.C = o(n)
private:
  int solve(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);

    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
      int take = nums[i] + dp[i - 2];
      int not_take = 0 + dp[i - 1];

      dp[i] = max(take, not_take);
    }

    return dp[n - 1];
  }

public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<int> with_first(nums.begin(), nums.end() - 1); // exclude last
    vector<int> with_last(nums.begin() + 1, nums.end());  // exclude first

    return max(solve(with_first), solve(with_last));
  }
};

class Solution // T.C = o(n) S.C = o(n) + o(n)-> stack space;
{
private:
  int max_amount(vector<int> &nums, int n, vector<int> &dp)
  {
    if (n == 0)
      return nums[0];
    if (n == 1)
      return max(nums[0], nums[1]);
    if (dp[n] != -1)
      return dp[n];

    int take = nums[n] + max_amount(nums, n - 2, dp);
    int not_take = max_amount(nums, n - 1, dp);

    return dp[n] = max(take, not_take);
  }

  int solve(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    if (n == 2)
      return max(nums[0], nums[1]);

    vector<int> dp(n, -1);
    return max_amount(nums, n - 1, dp);
  }

public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<int> with_first(nums.begin(), nums.end() - 1); // exclude last
    vector<int> with_last(nums.begin() + 1, nums.end());  // exclude first

    return max(solve(with_first), solve(with_last));
  }
};
