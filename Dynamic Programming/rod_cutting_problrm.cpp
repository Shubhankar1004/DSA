int help(int i,int n,vector<int> &price,vector<vector<int>> &dp)
{
	if (i==0)
	{
		if (i+1 <=n)
		{
			return price[i]*(n/(i+1));
		}
		else
		return 0;
	}
	if (dp[i][n]!=-1)
	return dp[i][n];
	int nottake=help(i-1,n,price,dp);
	int take=-1e9;
	if (i+1<=n)
	{
		take=price[i]+help(i,n-i-1,price,dp);
	}
	return dp[i][n]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(price.size()+1,vector<int> (n+1,-1));
	return help(price.size()-1,n,price,dp);
}
