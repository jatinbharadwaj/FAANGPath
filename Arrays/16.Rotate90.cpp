// https://leetcode.com/problems/rotate-image/submissions/
#include <iostream>
#include <vecotor>
using namespace std;
//<======================  APPROACH ========================>
/* 
    Intituion 
    00 01
    11 12 

    will become
    11 00
    12 01 

    Which Implies for i,j can have coloumn bottoms up
    So, we set K = matrix size -1 so that and it should not swap the element which has already been visited 
    hence marked a visited table 
*/
//<=======================    END   ========================>
class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {

        int n = matrix.size();
        vector<vector<bool> > visited(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++)
        {

            for (int j = 0, k = n - 1; j < n && k >= 0; j++, k--)
            {

                if (!visited[k][i])
                {
                    visited[i][j] = 1;
                    swap(matrix[i][j], matrix[k][i]);
                }
            }
        }
    }
};
int main()
{
    Solution S;
    vector<vector<int> > v(9, vector<int>(9, 1))
        S.rotate();
    return 0;
}