#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public: // o(n) o(1) -> Floyd's cycle detection
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance of the cycle (duplicate)
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

class Solution
{
public: // o(n) o(n)
    int findDuplicate(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> v(n, false);

        for (int i = 0; i < n; i++)
            if (v[nums[i]] == true)
                return nums[i];
            else
                v[nums[i]] = true;

        return 0;
    }
};

class Solution
{
public: // o(nlogn) o(1)
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return 0;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {3, 1, 3, 4, 2};

    cout << sol.findDuplicate(v) << endl;
}