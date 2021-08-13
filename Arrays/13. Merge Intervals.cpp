https : //leetcode.com/problems/merge-intervals/solution/
        class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals)
    {

        sort(intervals.begin(), intervals.end());

        vector<vector<int> > ans;

        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {

            if (end >= intervals[i][0])
            {
                if (end < intervals[i][1])
                    end = intervals[i][1];
            }

            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        int n = ans.size();
        if (n == 0 || start != ans[n - 1][0])
        {
            ans.push_back({start, end});
        }

        return ans;
    }
};