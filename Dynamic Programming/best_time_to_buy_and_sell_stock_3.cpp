class Solution {
public:
    int help(int i,int n,vector<int> &prices,vector<vector<vector<int>>> &dp,int buy,int cap)
    {
        if (i==n)
        return 0;
        if (cap==0)
        return 0;
        if (dp[i][buy][cap]!=-1)
        return dp[i][buy][cap];
        if (buy)
        return dp[i][buy][cap]=max(-prices[i]+help(i+1,n,prices,dp,0,cap),help(i+1,n,prices,dp,1,cap));
        else
        return dp[i][buy][cap]=max(prices[i]+help(i+1,n,prices,dp,1,cap-1),help(i+1,n,prices,dp,0,cap));
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return help(0,n,prices,dp,1,2);    
    }
};
