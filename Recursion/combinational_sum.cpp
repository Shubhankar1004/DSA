//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]
//Explanation:
//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//7 is a candidate, and 7 = 7.
//These are the only two combinations.



class Solution {
public:
    void comb(vector<int>& candidates, int target,int s,int i,vector<int> &temp,vector<vector<int>> &ans)
    {
        if (s>target)
            return;
        if (i==candidates.size())
        {
            if (s==target)
                ans.push_back(temp);
            return;
        }
        s+=candidates[i];
        temp.push_back(candidates[i]);
        comb(candidates,target,s,i,temp,ans);
        s-=candidates[i];
        temp.pop_back();
        comb(candidates,target,s,i+1,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        int s=0;
        comb(candidates,target,s,0,temp,ans);
        return ans;
    }
};
