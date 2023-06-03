#include <bits/stdc++.h> 
int help(int i,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    //if (target==0) return 1;  this base case doesnt work if there are zeroes also in the array
    if (i==0 )
    {
        if (target==0 and arr[0]==0) return 2;
        if (target==0 and arr[0]!=0) return 1;
        if (arr[0]==target) return 1; 
    }
    if (i==0 and target!=arr[i])return 0;
    if (dp[i][target]!=-1)
    return dp[i][target];

    int not_take=help(i-1,target,arr,dp);
    int take=0;
    if (arr[i]<=target)
    {
        take=help(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take + not_take;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int> (tar+1,-1));
    return help(num.size()-1,tar,num,dp);
}
