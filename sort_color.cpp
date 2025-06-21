#include <iostream>
#include <vector>
using namespace std;

class Solution
{ // o(n) o(1) and only one pass
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            { // nums[mid] == 2
                swap(nums[mid], nums[high--]);
            }
        }
    }
};

class Solution // o(n) o(1) but two - pass
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> temp = nums;
        int n = temp.size();
        int no_0 = 0, no_1 = 0, no_2 = 0;

        for (auto x : temp)
        {
            if (x == 0)
                no_0++;
            if (x == 1)
                no_1++;
            if (x == 2)
                no_2++;
        }

        temp.clear();

        for (int i = 0; i < n; i++)
        {
            if (no_0 > 0)
            {
                temp.push_back(0);
                no_0--;
            }
            else if (no_1 > 0)
            {
                temp.push_back(1);
                no_1--;
            }
            else
            {
                temp.push_back(2);
                no_2--;
            }
        }

        nums = temp;
    }
};

class Solution
{ // o(nlogn) o(1)
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        nums = temp;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
}