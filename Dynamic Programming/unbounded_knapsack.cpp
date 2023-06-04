#include <bits/stdc++.h> 
int help(int i,int w,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp)
{
    if (i==0)
    {
        if (weight[0]<=w)
        return profit[0]+help(i,w-weight[i],profit,weight,dp);
        else return 0;
    }
    if (dp[i][w]!=-1)
    return dp[i][w];
    int nottake=0+help(i-1,w,profit,weight,dp);
    int take=0;
    if (weight[i]<=w)
    {
        take=profit[i]+help(i,w-weight[i],profit,weight,dp);
    }
    return dp[i][w]=max(take,nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    //int n=weight.size();
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return help(n-1,w,profit,weight,dp);
}
