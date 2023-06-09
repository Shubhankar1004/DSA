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





//Another soln using DP - Memoization
//Time Complexity: O(N*2)
//*Space Complexity: O(2N) + O(N)



// class Solution {
// public:
//     int help(int i,vector<int> &prices,int n,vector<vector<int>> &dp,int buy)
//     {
//         if (i==n)
//         return 0;
//         if (dp[i][buy]!=-1)
//         return dp[i][buy];
//         if (buy) //if you can buy (that is you havent already bought sth) then take the max of buy/notbuy (1 meany option is available to buy and 0 means you cant buy coz you already own sth)
//         return dp[i][buy]=max(-prices[i]+help(i+1,prices,n,dp,0),0+help(i+1,prices,n,dp,1));
//         else
//         return dp[i][buy]=max(prices[i]+help(i+1,prices,n,dp,1),0+help(i+1,prices,n,dp,0));
//     }
//     int maxProfit(vector<int>& prices) 
//     {
//         int n=prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return help(0,prices,n,dp,1);
//     }
// };






//Tabulation
//In memoization we go from 0->n and hence for tabulation we go from n->1
//*Time Complexity: O(2N)
//*Space Complexity: O(2N)



// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2,-1)); //make it of n+1 size because dp[n][0]=0 as per the base case of memoization
//         dp[n][0] = dp[n][1] = 0;  
//         for(int i = n-1;i>=0;i--){
//             for(int buy = 0;buy<2;buy++){
//                 int profit =0;
//                 if(buy){
//                     profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);   
//                 }
//                 else{
//                     profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);   
//                 }
//                 dp[i][buy] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// };



//Space Optimization
//*Time Complexity: O(2N)
//*Space Complexity: O(4)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(2,0),curr(2,0);
        
        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                int profit =0;
                if(buy){
                    profit = max(-prices[i] + ahead[0], ahead[1]);   
                }
                else{
                    profit = max(prices[i] + ahead[1], ahead[0]);   
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};
