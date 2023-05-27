//recursion only has a time complexity of O(2^(m*n))

//DP soln works in a time complexity of O(m*n) - usually dp solns have TC = no of states of dp table.

// SC of O((n-1)+(m-1)) + O(n*m)   -- first part is the stack space which we try to remove in tabulation

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

//Tabualation -- removing the stack space
// same TC with SC as O(m*n) only

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i==0 and j==0)continue;
                else
                {
                    int up=0,left=0;
                    if (i>0)
                    up=dp[i-1][j];
                    if (j>0)
                    left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }  
        return dp[m-1][n-1];  
    }
};
