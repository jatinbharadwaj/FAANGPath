// https://leetcode.com/problems/merge-sorted-array/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int last = m + n - 1;

        if (m == 0)
        {
            nums1 = nums2;
        }

        while (m > 0 && n > 0 && last >= 0)
        {

            if (nums1[m - 1] == nums2[n - 1])
            {
                nums1[last--] = nums1[--m];
                nums1[last--] = nums2[--n];
            }
            else if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[last--] = nums1[--m];
            }
            else
            {
                nums1[last--] = nums2[--n];
            }
        }

        while (n > 0 && last >= 0)
        {
            nums1[last--] = nums2[--n];
        }

        while (m > 0 && last >= 0)
        {
            nums1[last--] = nums1[--m];
        }
    }
};