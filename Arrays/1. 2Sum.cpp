// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        // 2, target = 9, second = 7;
        map<int, int> store; // O(n) space
        int idx = 0;
        for (auto x : nums)
        {
            store[x] = idx++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int fi = nums[i];
            int second = target - fi;
            if (store[second] && i != store[second])
            {
                ans.push_back(i);
                ans.push_back(store[second]);
                break;
            }
        }
        return ans;
    }
};