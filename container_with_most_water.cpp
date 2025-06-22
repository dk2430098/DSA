#include <iostream>
#include <vector>
using namespace std;

class Solution
{ // o(n) o(1)
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int n = height.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            int Area = (j - i) * min(height[i], height[j]);
            max_area = max(max_area, Area);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return max_area;
    }
};

class Solution1
{ // o(n2) o(1)
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;

        for (int i = 0; i < height.size(); i++)
        {
            int area = 0;
            for (int j = i + 1; j < height.size(); j++)
            {
                area = (j - i) * min(height[i], height[j]);
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};

int main()
{
    Solution sol;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << sol.maxArea(height) << endl;
}