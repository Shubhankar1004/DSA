//following soln works in O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        while (i<m and j>=0)
        {
            if (matrix[i][j]==target)
            {
                return 1;
            }
            else if (matrix[i][j]<target)
            i++;
            else if (matrix[i][j]>target)
            j--;
        }  
        return 0;  
    }
};
