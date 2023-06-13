class Solution{
public:
    int help(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if (i==j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for (int k=i;k<j;k++)
        {
            int operations=arr[i-1]*arr[k]*arr[j]+help(i,k,arr,dp)+help(k+1,j,arr,dp);
            mini=min(mini,operations);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(1,n-1,arr,dp);
    }
};
