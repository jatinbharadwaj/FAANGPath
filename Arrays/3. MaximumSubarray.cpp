// https://leetcode.com/problems/maximum-subarray/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int currentSum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            currentSum = currentSum + nums[i];

            if (maxSum < currentSum)
                maxSum = currentSum;

            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};