//Memoization based approach
//Time Complexity -> O(N * 2 * 3)
//Space Complexity -> O(N * 2 * 3) + O(N + 2 + 3)


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




//Tabulation based approach
//Time Complexity -> O(N * 2 * 3)
//Space Complexity -> O(N * 2 * 3)




class Solution {
public:
	int solveTab(vector<int> &prices, int n)                 // BOTTOM UP APPROACH (Tabultaion)
	{
		vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
		// Base Cases
		for (int ind=0;ind<=n-1;ind++)
		{
			for (int buy=0;buy<=1;buy++)
				dp[ind][buy][0] = 0; // for cap=0, other 2 might be anything sp value will be 0
		}
		for (int buy=0;buy<=1;buy++)
		{
			for (int cap=0;cap<=2;cap++)
				dp[n][buy][cap] = 0;// if ind==n, other 2 might be anything dp value will be 0
		}

		for (int ind=n-1;ind>=0;ind--)
		{
			for (int buy=0;buy<=1;buy++)
			{
				int profit = 0;
				for (int cap=0;cap<=2;cap++)
				{
					if (buy)
						profit = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
					else
						profit = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);

					dp[ind][buy][cap] = profit;
				}
			}
		}
		return dp[0][1][2];
	}

	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		return solveTab(prices, n);
	}
};



//Space Optimization
//Time Complexity -> O(N * 2 * 3)
//Space Complexity -> O(1) actually its O(2*3) but that is same as O(1)





class Solution {
public:
	int solveOpti(vector<int> &prices, int n)                       // OPTIMIZED APPROACH
	{
		vector<vector<int>> after(2, vector<int> (3, 0));
		vector<vector<int>> curr(2, vector<int> (3, 0));

		for (int ind=n-1;ind>=0;ind--)
		{
			for (int buy=0;buy<=1;buy++)
			{
				int profit = 0;
				for (int cap=0;cap<=2;cap++)
				{
					if (buy)
						profit = max(-prices[ind] + after[0][cap], after[1][cap]);//just replace dp[i+1] with after and dp[i] with curr
					else
						profit = max(prices[ind] + after[1][cap-1], after[0][cap]);

					curr[buy][cap] = profit;
				}
			}
			after = curr; //ultimately make after =curr coz for next iteration this iterations curr will be after
		}
		return after[1][2];
	}

	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		return solveOpti(prices, n);
	}
};
