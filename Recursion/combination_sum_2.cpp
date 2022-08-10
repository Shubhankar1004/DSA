//Given a collection of candidate numbers (candidates) and a target number (target), 
//find all unique combinations in candidates where the candidate numbers sum to target.

//Each number in candidates may only be used once in the combination.

//Note: The solution set must not contain duplicate combinations.


class Solution {
public:
        void func(int ind, int tgt, vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds){
    if(tgt==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind; i<nums.size(); i++){
        if(i>ind && nums[i]==nums[i-1])
            continue;
        if(nums[i]>tgt){
            break;
        }
        ds.push_back(nums[i]);
        func(i+1,tgt-nums[i], nums,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    func(0,target,candidates,ans,ds);
    return ans;
}
};
