#include <iostream>
#include <vector>
using namespace std;

class Solution
{ // o(n) o(1) => Kaden's Algorithm
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            max_sum = max(sum, max_sum);

            if (sum < 0)
                sum = 0;
        }

        return max_sum;
    }
};

class Solution1 // o(n2) o(1)
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};

class Solution2
{ // o(n3) o(1)
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = i; j < nums.size(); j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                    sum += nums[k];
                max_sum = max(max_sum, sum);
            }
        }

        return max_sum;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}