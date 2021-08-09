// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int minimumSoFar = prices[0], currDifference = 0, maxDiff = 0;

        for (int i = 0; i < prices.size(); i++)
        {

            currDifference = prices[i] - minimumSoFar;

            if (currDifference > maxDiff)
                maxDiff = currDifference;

            if (prices[i] < minimumSoFar)
                minimumSoFar = prices[i];
        }

        return maxDiff;
    }
};