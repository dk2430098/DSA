#include <bits/sdtc++.h>
using namespace std;

class Solution
{ // T.C = o(n) S.C = o(constant) --> using vector of size 26
public:
  bool isAnagram(string s, string t)
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
};

class Solution
{ // T.C = o(n) S.C = o(n) --> using hash_map
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> mp;
    for (char ch : s)
      mp[ch]++;

    for (char ch : t)
    {
      if (mp.find(ch) != mp.end())
      {
        mp[ch]--;
        if (mp[ch] == 0)
          mp.erase(ch);
      }
      else
        return false;
    }

    return true;
  }
};

class Solution
{ // T.C = o(nlogn) S.C = o(1)
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != t[i])
        return false;
    }

    return true;
  }
};
