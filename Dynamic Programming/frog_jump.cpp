//coding ninjas wala

//memoization
// time complexity of O(2n)

#include<bits/stdc++.h>
int jump(int n,vector<int> heights,vector<int> &dp)
{
    if (n==0)
        return 0;
    if (n==1)
        return (abs(heights[1]-heights[0]));
    if (dp[n]!=-1)
        return dp[n];
    int l=INT_MAX,r=INT_MAX;
    if (n-1>=0)
    {
        l=jump(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    }
    if (n-2>=0)
    {
        r=jump(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]=min(l,r);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return jump(n-1,heights,dp);
}


//tabulation

#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n == 1) return 0;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i = 2; i < n; i++)
    {
     int l=INT_MAX,r=INT_MAX;
     l=dp[i-1] + abs(heights[i]-heights[i-1]);
     r=dp[i-2] + abs(heights[i]-heights[i-2]);
     dp[i] = min(l , r);
    }
    return dp[n-1];
}

// Space Optimization 

#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n == 1) return 0;
//     vector<int> dp(n+1,0);
    int a = 0;
    int b = abs(heights[1] - heights[0]);
    int c = b;
    for(int i = 2; i < n; i++)
    {
     int l=INT_MAX,r=INT_MAX;
     l= b + abs(heights[i]-heights[i-1]);
     r= a + abs(heights[i]-heights[i-2]);
     c = min(l , r);
     a = b;
     b = c;
    }
    return c;
}

