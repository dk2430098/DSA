#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int max_len = 0;
        unordered_map<int, int> mp;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == k)
            {
                max_len = i + 1;
            }

            if (mp.find(sum - k) != mp.end())
            {
                int len = i - mp[sum - k];
                max_len = max(max_len, len);
            }

            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }

        return max_len;
    }
};

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // code here
        int max_len = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                if (sum == k)
                    max_len = max(max_len, (j - i + 1));
            }
        }

        return max_len;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout << sol.longestSubarray(arr, 15) << endl;
}