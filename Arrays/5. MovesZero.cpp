// https://leetcode.com/problems/move-zeroes/
class Solution

{
public:
    void moveZeroes(vector<int> &nums)
    {

        int LastNonZeroFoundAt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[LastNonZeroFoundAt++] = nums[i];
            }
        }

        for (int i = LastNonZeroFoundAt; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};