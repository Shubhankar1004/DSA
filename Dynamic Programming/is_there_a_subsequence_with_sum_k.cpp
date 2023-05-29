//recursion takes O(2^n)
//memoization takes O(n*k)

#include <bits/stdc++.h>
bool help(int i,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    if (target==0) return true;
    if (i==0 and arr[i]==target) return true;
    if (i==0 and target!=arr[i])return false;
    if (dp[i][target]!=-1)
    return dp[i][target];

    bool not_take=help(i-1,target,arr,dp);
    bool take=false;
    if (arr[i]<=target)
    {
        take=help(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take | not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return help(arr.size()-1,k,arr,dp);
}
