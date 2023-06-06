#include <bits/stdc++.h> 

//It is similar to longest common subsequence but the else condition completely changes here
//only when s[i-1]==s[j-1] then dp[i][j]=1+dp[i-1][j-1] else dp[i][j]=0
//this is the dp table of tabulation code with 1 based indexing to adjust the base case
//      a b z d
//    0 1 2 3 4
//  0 0 0 0 0 0
//a 1 0 1 0 0 0
//b 2 0 0 2 0 0
//c 3 0 0 0 0 0
//d 4 0 0 0 0 1

#include <bits/stdc++.h> 
int lcs(string &s, string &t){
	//	Write your code here.
	int n=s.size();
	int m=t.size();
    int ans=0;
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<n+1;i++)
	for(int j=1;j<m+1;j++){
		if(s[i-1]==t[j-1]){
			dp[i][j]=1+dp[i-1][j-1];
			ans=max(ans,dp[i][j]);
		}
	}
	return ans;
}
