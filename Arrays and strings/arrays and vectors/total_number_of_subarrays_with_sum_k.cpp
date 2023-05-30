class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        int sum=0;int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if (sum==k)
            {
                ans++;
            }
            int x=sum-k;
            if (m.find(x)!=m.end())
            {
                ans+=m[x];
            }
            m[sum]++;
        }
        return ans;
    }
};
