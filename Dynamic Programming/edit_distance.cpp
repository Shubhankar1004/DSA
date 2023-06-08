//refer to notebook for detailed explanation

class Solution {
public:
    int help(int i,int j,string s1,string s2,vector<vector<int>> &dp)
    {
        if (i<0 and j>=0)
        return j+1;
        if (j<0 and i>=0)
        return i+1;
        if (i<0 and j<0)
        return 0;
        if (dp[i][j]!=-1)
        return dp[i][j];
        int replace=INT_MAX,remove=INT_MAX,insert=INT_MAX;
        if (s1[i]==s2[j])
        return dp[i][j]=help(i-1,j-1,s1,s2,dp);
        else
        {
            insert=1+help(i,j-1,s1,s2,dp);
            remove=1+help(i-1,j,s1,s2,dp);
            replace=1+help(i-1,j-1,s1,s2,dp);
        }
        int k=min(insert,remove);
        return dp[i][j]=min(k,replace);
    }
    int minDistance(string word1, string word2) 
    {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(n-1,m-1,word1,word2,dp);
    }
};
