//https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        //         int currArea = 0, maxArea = 0;
        //         for(int i=0;i<height.size()-1;i++){
        //             for(int j=i+1;j<height.size();j++){
        //                 int length = j-i;
        //                 int bredth = min(height[i],height[j]);

        //                 currArea = length*bredth;
        //                 maxArea = max(currArea,maxArea);
        //             }
        //         }
        //         return maxArea;

        //         TWO POINTER APPROACH

        int currArea = 0, maxArea = 0;
        int start = 0, end = height.size() - 1;
        while (start < end)
        {
            int length = end - start;
            int breadth = min(height[start], height[end]);
            currArea = length * breadth;
            maxArea = max(currArea, maxArea);

            if (height[start] < height[end])
            {
                start++;
            }
            else
                end--;
        }
        return maxArea;
    }
};

int main()
{
    Solution S;
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << S.maxArea(v);
}