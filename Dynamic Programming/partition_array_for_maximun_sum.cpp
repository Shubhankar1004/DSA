class Solution {
public:
    int help(int i,int n,vector<int> &arr,int k,vector<int> &dp)
    {
        if (i==n) return 0;
        if (dp[i]!=-1)
        return dp[i];
        int length=0;int maxi=-1e9;int maxans=-1e9;
        for (int j=i;j<min(n,i+k);j++)
        {
            length++;
            maxi=max(maxi,arr[j]);
            int sum=length*maxi+help(j+1,n,arr,k,dp);
            maxans=max(maxans,sum);
        }
        return dp[i]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n =arr.size();
        vector<int> dp(n,-1);
        return help(0,n,arr,k,dp);   
    }
};
