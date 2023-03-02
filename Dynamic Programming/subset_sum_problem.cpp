//0-1 knapsack type approach



class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here 
        int dp[arr.size()+1][sum+1];
        for (int i=0;i<arr.size()+1;i++)
        {
            for (int j=0;j<sum+1;j++)
            {
                if (i==0)
                dp[i][j]=0;
                if (j==0)
                dp[i][j]=1;
            }
        }
        for (int i=1;i<arr.size()+1;i++)
        {
            for (int j=1;j<sum+1;j++)
            {
                if (arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[arr.size()][sum];
    }
};
