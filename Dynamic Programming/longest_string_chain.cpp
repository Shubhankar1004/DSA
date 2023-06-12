class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    bool compare(string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        if (n+1!=m) return false;
        int i=0,j=0;
        while(j<m)
        {
            if (i<n and s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if (i==n and j==m)
        return true;
        else
        return false;
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (compare(words[j],words[i]) and dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        } 
        return maxi; 
    }
};
