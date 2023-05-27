#include <bits/stdc++.h>

class Solution {
public:
    int help(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)  // use & to pass parameters - takes less time
    {
         if (i<0 || j<0)
        return INT_MAX; //you dont want this path to be added as it goes out of bounds
        if (i==0 and j==0)
        return dp[i][j]=grid[i][j];
        if (dp[i][j]!=-1)
        return dp[i][j];
        
        int up=help(i-1,j,dp,grid);
        int left=help(i,j-1,dp,grid);
        return dp[i][j]=min(left,up)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        help(m-1,n-1,dp,grid);
        return dp[m-1][n-1];
    }
};
