#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public: // o(n) o(1)
    int maximumSumSubarray(vector<int> &arr, int k)
    {

        int max_sum = 0;
        int sum = 0;

        for (int i = 0; i < k; i++)
            sum += arr[i];

        for (int i = 0; i < arr.size() - k; i++)
        {
            max_sum = max(max_sum, sum);
            sum += (arr[i + k] - arr[i]);
        }

        max_sum = max(max_sum, sum);
        return max_sum;
    }
};

class Solution
{
public: // o(nk) o(1)
    int maximumSumSubarray(vector<int> &arr, int k)
    {

        int max_sum = 0;

        for (int i = 0; i < arr.size() - k; i++)
        {
            int sum = 0;
            for (int j = i; j < (i + k); j++)
                sum += arr[j];
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {100, 200, 300, 400};
    int k = 2;

    cout << sol.maximumSumSubarray(arr, k);
}