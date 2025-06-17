#include <iostream>
#include <vector>
using namespace std;

class Solution
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

int main()
{
    Solution sol;
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
