// //Very very similar to buy and sell stock and to your amazon question

// class Solution {
// public:
//     int maxProfit(vector<int>& prices)
//     {
//         int i=prices.size()-1;int maxi=prices[prices.size()-1];int ans=0;
//         while (i>=0)
//         {
//             if (prices[i]<maxi)
//             {
//                 ans+=maxi-prices[i];
//                 maxi=prices[i];
//             }
//             else
//             {
//                 maxi=prices[i];
//             }
//             i--;
//         }
//         return ans;
//     }
// };

//Another soln using DP

class Solution {
public:
    int help(int i,vector<int> &prices,int n,vector<vector<int>> &dp,int buy)
    {
        if (i==n)
        return 0;
        if (dp[i][buy]!=-1)
        return dp[i][buy];
        if (buy) //if you can buy (that is you havent already bought sth) then take the max of buy/notbuy (1 meany option is available to buy and 0 means you cant buy coz you already own sth)
        return dp[i][buy]=max(-prices[i]+help(i+1,prices,n,dp,0),0+help(i+1,prices,n,dp,1));
        else
        return dp[i][buy]=max(prices[i]+help(i+1,prices,n,dp,1),0+help(i+1,prices,n,dp,0));
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return help(0,prices,n,dp,1);
    }
};
