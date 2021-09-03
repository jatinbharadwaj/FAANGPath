// // https://leetcode.com/problems/3sum/
// **Brute force **

// ```
#include <iostream>
using namespace std;
class threeSome
{
    sort(nums.begin(), nums.end());
    set<vector<int> > ans;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int num = nums[i] + nums[j] + nums[k];
                if (num == 0)
                {
                    ans.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    vector<vector<int> > realAns;
    for (auto i : ans)
    {
        realAns.push_back(i);
    }
    return (realAns);
}
// ``` TIME COMPLEXITY : O(N ^ 3 + NLOGN)

//                       *
//                       *Ussing Map and Set Solution **O(N ^ 2) Solution
//    ``` set<vector<int> > ansSet;

public : vector<vector<int> >
         threeSum(vector<int> &nums)
{

    if (nums.size() < 3)
    {
        return {};
    }
    unordered_map<int, int> storage;
    sort(nums.begin(), nums.end());

    int idx = 0;

    for (auto i : nums)
    {
        storage[i] = idx++;
    }

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int target = -nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (storage.count(target - nums[j]) > 0 && storage[target - nums[j]] > j)
            {
                ansSet.insert({-target, nums[j], target - nums[j]});
            }
        }
    }

    vector<vector<int> > ans;
    for (auto i : ansSet)
    {
        ans.push_back(i);
    }

    return ans;
}
// ```

//     **TWO POINTER'S APPROACH**
// ``` vector<vector<int> >
int threeSum(vector<int> &num)
{

    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++)
    {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back)
        {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else
            {
                vector<int> triplet = {num[i], num[front], num[back]};
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1])
                    front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2])
                    back--;
            }
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i])
            i++;
    }

    return res;
}
