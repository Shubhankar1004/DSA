//similar to subset sum


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for (int i=0;i<N;i++)
        sum+=arr[i];
        if (sum%2==1)
        return 0;
        sum/=2;
        int dp[N+1][sum+1];
        for (int i=0;i<N+1;i++)
        {
            for (int j=0;j<sum+1;j++)
            {
                if (i==0)
                dp[i][j]=0;
                if (j==0)
                dp[i][j]=1;
            }
        }
        for (int i=1;i<N+1;i++)
        {
            for (int j=1;j<sum+1;j++)
            {
                if (arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
};
