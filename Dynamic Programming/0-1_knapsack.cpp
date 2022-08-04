int dp[1002][1002];
class Solution
{
   // memset(mat,-1,sizeof(mat[0][0])*1002*1002);
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int n)
    {
       if(W==0 || n==0) 
       return 0;
       
       if(dp[n][W]!=-1) 
       return dp[n][W];
       
       if(wt[n-1]<=W)
       return dp[n][W]=max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
       
       else if(wt[n-1]>W)
       return dp[n][W]=solve(W,wt,val,n-1);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
     memset(mat,-1,sizeof(mat)); //cannot be declared globally
     int ans;
     ans=solve(W,wt,val,n);
     return ans;
    }
};
