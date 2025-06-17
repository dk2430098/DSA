#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++)
            for (int j = i + 1; j < prices.size(); j++)
                if (prices[i] < prices[j])
                    profit = max(profit, prices[j] - prices[i]);

        return profit;
    }
};

int main()
{
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int profit = sol.maxProfit(prices);

    cout << profit << endl;
}