#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution // T.C = o(n) S.C = o(n)
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int max_len = 0, l = 0;

        for (int r = 0; r < s.size(); r++)
        {
            char ch = s[r];
            if (mp.find(ch) != mp.end())
            {
                l = max(l, mp[ch] + 1);
            }
            mp[ch] = r;
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};

class Solution
{ // o(n3) o(n)
public:
    bool repeated(string temp)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = i + 1; j < temp.size(); j++)
            {
                if (temp[i] == temp[j])
                    return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string temp = "";
            for (int j = i; j < s.size(); j++)
            {
                temp += s[j];
                if (!repeated(temp))
                {
                    max_len = max(max_len, (int)temp.size());
                }
                else
                    break;
            }
        }

        return max_len;
    }
};

int main()
{
    Solution sol;

    string s = "abcabcbb";

    cout << sol.lengthOfLongestSubstring(s) << endl;
}