#include <bits/sdtc++.h>
using namespace std;

class Solution // T.C = o(n3)  S.C = o(n)
{
private:
  string cut(int i, int j, string s)
  {
    string ans = "";

    for (; i <= j; i++)
      ans += s[i];
    return ans;
  }
  bool check(int i, int j, string s)
  {
    while (i <= j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    string ans = "";

    for (int i = 0; i < n; i++)
    {
      for (int j = n - 1; j >= i; j--)
      {
        if (s[i] == s[j] && check(i, j, s))
        {
          if (ans.size() < (j - i + 1))
            ans = cut(i, j, s);
        }
      }
    }

    return ans;
  }
};