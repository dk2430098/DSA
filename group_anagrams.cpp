#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n2*k) S.C = o(n*k) --> k is average lenght of string
private:
  bool check(string s, string t)
  {
    if (s.size() != t.size())
      return false;
    vector<int> v(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
      int x = v[s[i] - 'a'];
      v[s[i] - 'a'] = ++x;
    }

    for (int i = 0; i < t.size(); i++)
    {
      int x = v[t[i] - 'a'];
      if (x <= 0)
        return false;
      v[t[i] - 'a'] = --x;
    }

    return true;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<string> temp = strs;
    if (strs.size() <= 1)
      return {strs};
    vector<vector<string>> ans;

    for (int i = 0; i < strs.size(); i++)
    {
      if (strs[i] == "Deepak123")
        continue;
      vector<string> v;
      v.push_back(strs[i]);
      for (int j = i + 1; j < strs.size(); j++)
      {
        string s = strs[i];
        string t = strs[j];
        if (check(s, t))
        {
          v.push_back(t);
          strs[j] = "Deepak123";
        }
      }
      ans.push_back(v);
    }

    return ans;
  }
};