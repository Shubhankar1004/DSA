//no of insertion = size of string - longest palindromic subsequence

//and you can calculate longest palindromic subsequence by reversing s and finding LCS of s and reverse(s)

class Solution {
public:
    int minInsertions(string s) 
    {
        int n= s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s1=s;reverse(s.begin(),s.end());
        string s2=s;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int longest=dp[n][n];
        return n-longest;
    }
};
