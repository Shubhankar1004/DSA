//first we generate the dp table of subsequence with sum k
//then use that dp table to calculate min difference
//last row of dp table is basically is there a subsequence with sum i of size nums.size()
//if that is true then ttl sum of array - i(target sum) gives sum of remaining array
//mini=min(mini,ttl sum of array-i) if dp[n-1][i]==T

//the following code only works for positive integers as dp cant store negative indices

class Solution {
public:
    bool help(int i,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    if (target==0) return true;
    if (i==0 and arr[i]==target) return true;
    if (i==0 and target!=arr[i])return false;
    if (dp[i][target]!=-1)
    return dp[i][target];

    bool not_take=help(i-1,target,arr,dp);
    bool take=false;
    if (arr[i]<=target)
    {
        take=help(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take | not_take;
}
    int minimumDifference(vector<int>& nums) 
    {
        int n=nums.size();long long sum=0;
        for (int i=0;i<n;i++)
        sum+=nums[i];int mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        help(n-1,sum,nums,dp);  
        for (long long i=0;i<sum;i++)
        {
            if (dp[n-1][i]==1)
           {
               if (abs(sum-i-i)<mini)
               mini=abs(sum-i-i);
           }
        } 
        return mini; 
    }
};
