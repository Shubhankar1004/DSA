class Solution {
public:
    int help(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &triangle)
    {
        if (i==triangle.size()-1)
        return triangle[i][j];
        if (dp[i][j]!=-1)
        return dp[i][j];
        int d=triangle[i][j]+help(i+1,j,dp,triangle);
        int dia=triangle[i][j]+help(i+1,j+1,dp,triangle);
        return dp[i][j]=min(d,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
           int n=triangle.size();
           vector<vector<int>> dp(n,vector<int>(n,-1));
           return help(0,0,dp,triangle); 
    }
};
