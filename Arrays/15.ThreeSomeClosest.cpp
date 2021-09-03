// https : //leetcode.com/problems/3sum-closest/submissions/
#include <iostream>
#include <vector>
using namespace std;

//<======================  APPROACH ========================>
/*
    Sort the array fir humme direction pta hogi kee kis taraf move karna hai 
    Consider First, Second and Third Position{Start, start+1, last}
    Case 1;
    Jab tak currentsum taget s bada hai toh mtlb bada hai toh last ko left move kar do
    Case 2;
    agr currentsum target s chota hai toh second ko right move karo 
    Case 3;
    agr currentsum target k equal hai toh return kar do
    Step 2;
    ek run k baad first ko move karo and repeat 1,2,3
    CurrentSum ko compare karte raho har iteration mein agr abs chota ho toh closest ko update kar do 
*/
//<=======================    END   ========================>
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int closest = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int currentSum = nums[i] + nums[j] + nums[k];

                if (currentSum == target)
                {
                    return currentSum;
                }

                if (abs(target - currentSum) < abs(target - closest))
                {
                    closest = currentSum;
                }

                if (currentSum > target)
                    k--;

                else if (currentSum < target)
                    j++;
            }
        }
        return closest;
    }
};

int main()
{

    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    cout << s.threeSumClosest(v, 9);
    return 0;
}
