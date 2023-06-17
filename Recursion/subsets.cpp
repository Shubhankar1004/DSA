class Solution {
public:
    void help(int i,int n,vector<int> &temp,vector<vector<int>> &ans,vector<int> &nums)
    {
        if (i>=n)
        {
            ans.push_back(temp);
            //temp.clear();
            return;
        }
        temp.push_back(nums[i]);
        help(i+1,n,temp,ans,nums);
        temp.pop_back();
        help(i+1,n,temp,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        help(0,nums.size(),temp,ans,nums);   
        return ans;
    }
};
