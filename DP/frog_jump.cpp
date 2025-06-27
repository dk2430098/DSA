class Solution
{ // T.C = o(n) S.C = o(n)+o(n)
public:
  vector<int> dp;
  int cost(int n, vector<int> &height)
  {
    if (n == 0)
      return 0;
    if (dp[n] != -1)
      return dp[n];
    int left = cost(n - 1, height) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
      right = cost(n - 2, height) + abs(height[n] - height[n - 2]);
    return dp[n] = min(left, right);
  }
  int minCost(vector<int> &height)
  {
    // Code here
    int n = height.size();
    dp.resize(height.size());
    dp.assign(n, -1);
    return cost(height.size() - 1, height);
  }
};

class Solution
{ // T.C = o(n) S.C = o(n)
public:
  int minCost(vector<int> &height)
  {
    // Code here
    int n = height.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
      int fs = dp[i - 1] + abs(height[i - 1] - height[i]);
      int ss = INT_MAX;
      if (i > 1)
        ss = dp[i - 2] + abs(height[i] - height[i - 2]);

      dp[i] = min(fs, ss);
    }

    return dp[n - 1];
  }
};

class Solution
{ // T.C = o(n) S.C = o(1)
public:
  int minCost(vector<int> &height)
  {
    // Code here
    int n = height.size();
    int pre = 0, pre2 = 0;

    for (int i = 1; i <= n - 1; i++)
    {
      int fs = pre + abs(height[i] - height[i - 1]);
      int ss = INT_MAX;
      if (i > 1)
        ss = pre2 + abs(height[i] - height[i - 2]);
      int curr = min(fs, ss);
      pre2 = pre;
      pre = curr;
    }

    return pre;
  }
};