// https://leetcode.com/problems/product-of-array-except-self/submissions/
#include <iostream>
using namespace std;
//<======================  APPROACH ========================>
/* 
    Prefix and PostFix multiplication arrays are maintained at any given point product except itself is 
    product of number ahead * products of number begind
*/
//<=======================    END   ========================>
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> leftProduct(n, 0);
        vector<int> rightProduct(n, 0);

        rightProduct[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            rightProduct[i] = rightProduct[i - 1] * nums[i];
        }

        leftProduct[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            leftProduct[j] = leftProduct[j + 1] * nums[j];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {

            // cout<<leftProduct[i]<<"  -  "<<rightProduct[i]<<endl;
            if (i > 0 && i < n - 1)
                ans.push_back(leftProduct[i + 1] * rightProduct[i - 1]);
            else if (i == 0)
                ans.push_back(leftProduct[i + 1]);
            else if (i == n - 1)
                ans.push_back(rightProduct[i - 1]);
        }

        return ans;
    }
};
int main()
{
    Solution S;
    vetor<int> v{1, 2, 3, 4};
    S.productExceptSelf(v);
    return 0;
}