class Solution {
  public:
    long long fib(long long n,vector<long long> &dp)
    {
        if (n<=1)
        return n;
        if (dp[n]!=-1)
        return dp[n];
        return (dp[n]=(fib(n-1,dp)%1000000007+fib(n-2,dp)%1000000007)%1000000007);
    }
    long long int nthFibonacci(long long int n)
    {
        // code here
        vector<long long>dp(n+1,-1);
        
        return fib(n,dp);
    }
};
