//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]
//Explanation:
//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//7 is a candidate, and 7 = 7.
//These are the only two combinations.



class Solution {
public:
    void help(int i,int target,vector<vector<int>> &ans,vector<int> &temp,vector<int> &candidates,int n)
    {
        if (i==n)
        {
            if (target==0)
            ans.push_back(temp);
            return;
        }
        if (candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            help(i,target-candidates[i],ans,temp,candidates,n);
            temp.pop_back();
        }
        
        help(i+1,target,ans,temp,candidates,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n=candidates.size();
        vector<vector<int>> ans;vector<int> temp;
        help(0,target,ans,temp,candidates,n);
        return ans;
    }
};
