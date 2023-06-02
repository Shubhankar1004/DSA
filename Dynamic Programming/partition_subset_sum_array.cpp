// almost exactly same as subsequence with sum k?
// calculate sum of array and then k=sum/2 ... now run above code on this k
// if sum/2 ki subsequence hai then remaining array will have sum as sum/2 -> hence 2 subarrays 


class Solution {
public:
    bool help(int sum,vector<int> &nums,vector<vector<int>> &dp,int i)
    {
        if (sum==0)
        return true;
        if (i==0 and nums[i]==sum)
        return true;
        if (i==0 and nums[i]!=sum)
        return false;
        if (dp[i][sum]!=-1)
        return dp[i][sum];
        bool taken=false;
        bool not_taken=help(sum,nums,dp,i-1);
        if (nums[i]<=sum)
        {
            taken=help(sum-nums[i],nums,dp,i-1);
        }
        return dp[i][sum]=taken | not_taken;
    }
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum=0;
        for (int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if (sum%2==1)
        return false;
        else
        {
            sum=sum/2;
            vector<vector<int>> dp(n,vector<int> (sum+1,-1));
            return help(sum,nums,dp,n-1);
        }   
    }
};
