//reverse s and apply longest common subsequence on s1 and s2
//coz aage and peeche se same hona padega to be palindromic and hence the above logic
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string s1=s;reverse(s.begin(),s.end());
        string s2=s;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for (int i=1;i<=s1.size();i++)
        {
            for (int j=1;j<=s2.size();j++)
            {
                if (s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
