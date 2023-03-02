//exactly same as fibonacci


#include <bits/stdc++.h>
long long solve(long long nStairs,vector<long long> &dp)
{
    if (nStairs<=1)
    return nStairs;
    if (dp[nStairs]!=-1)
    return dp[nStairs];
    return (dp[nStairs]=(solve(nStairs-1,dp)%1000000007+solve(nStairs-2,dp)%1000000007)%1000000007);
}

long long countDistinctWays(int nStairs) 
{
    //  Write your code here.
    vector<long long> dp(nStairs+2,-1);
    long long ans=solve(nStairs+1,dp);
    return ans;
}