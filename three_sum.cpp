#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{ // o(~n2) o(1)->excluding outpue
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

class Solution1
{
    // Overall: O(n^2)

    // Sorting: O(n log n)

    // Inner two-pointer scan: O(n) for each elemen
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> temp;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];

                if (temp.find(-sum) != temp.end())
                {
                    vector<int> triple = {nums[i], nums[j], -sum};
                    sort(triple.begin(), triple.end());
                    s.insert(triple);
                }

                temp.insert(nums[j]);
            }
        }

        for (auto triple : s)
            ans.push_back(triple);

        return ans;
    }
};

class Solution2
{
public: // o(n3) o(n)
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int sum = 0;
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                for (int k = j + 1; k < nums.size(); k++)
                {
                    sum += nums[k];
                    if (sum == 0)
                    {
                        vector<int> triple = {nums[i], nums[j], nums[k]};
                        sort(triple.begin(), triple.end());
                        s.insert(triple);
                    }
                    sum -= nums[k];
                }
                sum -= nums[j];
            }
            sum = 0;
        }

        for (auto triple : s)
            ans.push_back(triple);
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = sol.threeSum(v);
}