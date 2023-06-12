//TC of O(n*n) and space complexity of O(2*n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);int maxi=0,last_ind=0;
        for (int i=1;i<n;i++)
        {
            hash[i]=i;
            for (int prev=0;prev<i;prev++)
            {
                if (nums[i]%nums[prev]==0 and dp[i]<1+dp[prev])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if (dp[i]>maxi)
            {
                maxi=dp[i];
                last_ind=i;
            }
        }
        vector<int> ans;ans.push_back(nums[last_ind]);
        while (hash[last_ind]!=last_ind)
        {
            last_ind=hash[last_ind];
            ans.push_back(nums[last_ind]);
        }
        return ans;
    }
};
