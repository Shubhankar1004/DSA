class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        } 
        // int longest=dp[n][m];
        // return n+m-longest;  
        int i=n,j=m;
        string ans="";
        while(i>0 and j>0)
        {
            if (str1[i-1] == str2[j-1])
            {
                ans+=str1[i-1];
                //m1[str1[i-1]]--;m2[str2[j-1]]--;
                i--;j--;
            }
            else
            {
                if (dp[i-1][j]>dp[i][j-1])
                {
                    ans+=str1[i-1];
                    i--;
                }
                else
                {
                    ans+=str2[j-1];
                    j--;
                }
            }
        } 
        if (j==0 and i>=1)
        {
            while(i>=1)
            {
                ans+=str1[i-1];
                i--;
            }
        }
        if (i==0 and j>=1)
        {
            while(j>=1)
            {
                ans+=str2[j-1];
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
