#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{ // o(n3) o(1)(exclude output space)
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum < target)
                    {
                        k++;
                    }
                    else if (sum > target)
                    {
                        l--;
                    }

                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return ans;
    }
};

class Solution1 // o(n3) o(n)
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                unordered_set<long long> seen;
                for (int k = j + 1; k < n; k++)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long needed = (long long)target - sum;

                    if (seen.find(needed) != seen.end())
                    {
                        vector<int> quad = {nums[i], nums[j], nums[k], (int)needed};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

class Solution2 // o(n4)
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int a = 0; a < nums.size(); a++)
        {
            for (int b = a + 1; b < nums.size(); b++)
            {
                for (int c = b + 1; c < nums.size(); c++)
                {
                    for (int d = c + 1; d < nums.size(); d++)
                    {
                        if ((nums[a] + nums[b] + nums[c] + nums[d]) == target)
                        {
                            vector<int> quadruplets = {nums[a], nums[b], nums[c], nums[d]};
                            sort(quadruplets.begin(), quadruplets.end());
                            s.insert(quadruplets);
                        }
                    }
                }
            }
        }

        for (auto quadruplets : s)
            ans.push_back(quadruplets);

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> ans = sol.fourSum(nums, target);
}