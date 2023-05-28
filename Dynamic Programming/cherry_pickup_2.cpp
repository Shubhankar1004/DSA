//TC : O(n*m*m)
//SC : O(n) + O(n*m*m)

class Solution {
public:
    int help(int i,int j1,int j2,vector<vector<vector<int>>> &dp,vector<vector<int>> &grid,int m)
    {
        if (j1<0 || j2<0 || j1>=m || j2>=m)
        return -1e8;
        if (i==grid.size()-1)
        {
            if (j1==j2)
            return grid[i][j1];
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if (dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
        int maxi=0;
        for (int k1=-1;k1<2;k1++)
        {
            for (int k2=-1;k2<2;k2++)
            {
                if (j1==j2)
                maxi=max(maxi,grid[i][j1]+help(i+1,j1+k1,j2+k2,dp,grid,m));
                else
                maxi=max(maxi,grid[i][j1]+grid[i][j2]+help(i+1,j1+k1,j2+k2,dp,grid,m));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int ans=help(0,0,m-1,dp,grid,m);
        return ans;    
    }
};
