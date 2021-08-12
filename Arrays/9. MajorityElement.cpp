// https://leetcode.com/problems/majority-element/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main()
{
    Solution S;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    cout << "HEllo Debugger";
    S.majorityElement(nums);
    return 0;
}