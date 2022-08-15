//memoization in tc:O(n) and space:2*O(n)

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


//tabulation in tc:O(n) and space O(n)

class Solution {
  public:
    
    long long int nthFibonacci(long long int n)
    {
        // code here
        vector<long long int>dp(n+1,-1);
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<=n;i++){
           dp[i]=(dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007;
       }
       return dp[n];
    }
};


//O(n) tc and O(1) space


# define m 1000000007;
            
        long long  int firstno = 0;
        long long int secondno = 1;
        
        for (int i = 2; i <= n; i++){
            long long int currno = (firstno+secondno) % m;
            firstno = secondno;
            secondno = currno;
        }
        
        return secondno;
