class Solution {
public:
    int sum(vector<int>&nums,int i,int t,int s)
    {
        if (i==nums.size())
        {
            if (s==t)
                return 1;
            else
                return 0;
        }
        s+=nums[i];
        int l=sum(nums,i+1,t,s);
        s-=nums[i];
        int r=sum(nums,i+1,t,s);
        return l+r;
    }
    int numSubseq(vector<int>& nums, int target) 
    {
        int s=0;
        return (sum(nums,0,target,s)%1000000007);
        
    }
};
