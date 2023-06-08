class Solution {
public:
    int help(int i,int j,string &s,string &t,vector<vector<int>> &dp)
    {
        if (i<0 and j>=0) return 0;
        if (j<0) return 1;
        if (dp[i][j]!=-1)
        return dp[i][j];
        if (s[i]==t[j])
        {
            return dp[i][j]=help(i-1,j-1,s,t,dp) + help(i-1,j,s,t,dp); //take and move to i-1 and j-1 + dont take and move to i-1 bcoz you might want to take t[j] from i-1 like in babgbag, when matching g of bag you can match it to last g of bagbgbag or second last g and hace f(i-1,j)
        }
        else
        {
            return dp[i][j]=help(i-1,j,s,t,dp); // if not matching simply move i backward to find better possibilities
        }
    }
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return help(m-1,n-1,s,t,dp);    
    }
};
