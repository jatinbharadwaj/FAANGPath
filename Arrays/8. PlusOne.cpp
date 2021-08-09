// https://leetcode.com/problems/plus-one/
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        int n = digits.size();
        // vector<int> ans;
        int carry = 1, sum = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            sum = carry + digits[i];
            // ans.push_back(sum%10);
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry)
        {
            // ans.push_back(carry);
            digits.insert(digits.begin(), carry);
        }
        // reverse(ans.begin(),ans.end());
        // return ans;
        return digits;
    }
};