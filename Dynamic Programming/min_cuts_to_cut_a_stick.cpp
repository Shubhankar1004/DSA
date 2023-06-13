class Solution {
public:
    int help(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
    {
        if (i>j) return 0;
        if (dp[i][j]!=-1)
        return dp[i][j];
        int mini=1e9;
        for (int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+help(i,ind-1,cuts,dp)+help(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return help(1,cuts.size()-2,cuts,dp);    
    }
};
