#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {}; // Return empty if no pair found
    }
};

class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            // Check if complement exists
            if (mp.find(complement) != mp.end())
            {
                return {mp[complement], i}; // Found the pair
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        return {}; // Return empty vector if no pair found
    }
};

int main()
{
    Solution2 sol;
    vector<int> v = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(v, target);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
