//memoization

int max(vector<int>& nums,int i,vector<int> &dp,int n)
{
    if(i==0)
    {
        return nums[i];
    }
    else if(i<0)
        return 0;
    if (dp[i]!=-1)
        return dp[i];
    int left=nums[i]+max(nums,i-2,dp,n);
    int right=max(nums,i-1,dp,n);
    return dp[i]=max(left,right);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    int ans=max(nums,n-1,dp,n);
    return ans;
}


//tabulation



int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    dp[0]=nums[0];
    for (int i=1;i<n;i++)
    {
        int left=0;
        if (i-2<0)
            left=0+nums[i];
        if (i-2>=0)
        left=nums[i]+dp[i-2];
        int right=dp[i-1];
        dp[i]=max(left,right);
    }
    return dp[n-1];
    
}
