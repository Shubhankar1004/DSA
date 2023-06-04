class Solution {
public:
    int help(int i,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        if (i==0)
        {
            if (amount%coins[0]==0)
            return amount/coins[0];
            else
            return 1e9; //as its not possible to achieve amount with given coins and moreover take is already 1e9 and base case can only be achieved via not take(i-1 call) so if min of both is 1e0 then it means amount not achievable -> this check has been applied in thr org function
        }
        if (dp[i][amount]!=-1)
        return dp[i][amount];
        int not_take=0+help(i-1,amount,coins,dp);
        int take=1e9; //you dont want this as 0 bcoz if coins[i]>amt then min of 0 and not take will be 0 and hance take should be initialized to INT_MAX to handle min condition
        if (coins[i]<=amount)
        {
            take=1+help(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int x=help(n-1,amount,coins,dp);    
        if(x!=1e9) return x;
        else return -1;
    }
};
