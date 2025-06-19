#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {

            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= end)
            {
                end = max(end, currEnd);
            }
            else
            {
                ans.push_back({start, end});
                start = currStart;
                end = currEnd;
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> ans = sol.merge(v);
}