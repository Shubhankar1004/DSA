//recursion only has a time complexity of O(2^(m*n))

//DP soln works in a time complexity of O(m*n) - usually dp solns have TC = no of states of dp table.

// SC of O((n-1)+(m-1)) + O(n*m)

class Solution {
public:
    int help(int i,int j,vector<vector<int>> &dp)
    {
        if (i==0 and j==0)
        return 1;
        
        if (i<0 || j<0) return 0;
        if (dp[i][j]!=-1)
        return dp[i][j];
        int left=help(i-1,j,dp);
        int right=help(i,j-1,dp);
        int sum=left + right;
        return dp[i][j]=sum;
    }
    int uniquePaths(int m, int n) 
    {
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=help(m-1,n-1,dp);
        return ans;
    }
};
