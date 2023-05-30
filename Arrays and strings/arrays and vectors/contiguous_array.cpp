//max length on subarray with equal no of zeroes and ones

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int> mp;int sum=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)
            nums[i]=-1;
        }    
        //int sum=0;
        int maxi=0;
        for (int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if (sum==0)
            {
                maxi=max(maxi,i+1);
            }
            if (mp.find(sum)!=mp.end())
            {
                maxi=max(maxi,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return maxi;
    }
};
