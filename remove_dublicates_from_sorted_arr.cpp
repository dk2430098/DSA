#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{ // o(n) o(1)
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

class Solution // Time: O(n log n) (due to set insertion) o(n) -> here we have used extra-space
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());

        int i = 0;
        for (int val : st)
            nums[i++] = val;

        return st.size();
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 1, 2};
    cout << sol.removeDuplicates(nums) << endl;
}