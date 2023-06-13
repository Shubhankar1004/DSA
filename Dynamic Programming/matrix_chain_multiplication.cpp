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


//Tabulation


class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=0;i<n;i++)
        dp[i][i]=0;
        
        for (int i=n-1;i>0;i--)
        {
            for (int j=i+1;j<n;j++)
            {
                int mini=1e9;//necessary to initialize it here only
                for (int k=i;k<j;k++)
                {
                    int op=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,op);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};
