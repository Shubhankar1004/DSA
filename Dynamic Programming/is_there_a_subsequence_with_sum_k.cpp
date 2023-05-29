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


//Tabulation

bool tab(int n,int tar,vector<int>&a){

    

    vector<vector<bool>>dp(n,vector<bool>(tar+1,0));

 

    for(int i=0;i<n;i++)

    dp[i][0] = 1;

    dp[0][a[0]] = 1;

    for(int i =1;i<n;i++){

        for(int j=1;j<=tar;j++){

            bool excl = dp[i-1][j];

            bool inclu = 0;

            if(j-a[i]>=0)

            inclu = dp[i-1][j-a[i]];

            dp[i][j] = (inclu | excl);

        }

    }

    if(dp[n-1][tar]) return 1;

    return 0;

}
