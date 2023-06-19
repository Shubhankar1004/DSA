//Given a collection of candidate numbers (candidates) and a target number (target), 
//find all unique combinations in candidates where the candidate numbers sum to target.

//Each number in candidates may only be used once in the combination.

//Note: The solution set must not contain duplicate combinations.


// //following code gives TLE


// class Solution {
// public:
//     void help(int i,int target,set<vector<int>> &ans,vector<int> &temp,vector<int> &candidates,int n)
//     {
//         if (i==n)
//         {
//             if (target==0)
//             {
//                 ans.insert(temp);
//             }
//             return;
//         }
//         if (candidates[i]<=target)
//         {
//             temp.push_back(candidates[i]);
//             help(i+1,target-candidates[i],ans,temp,candidates,n);
//             temp.pop_back();
//         }
        
//         help(i+1,target,ans,temp,candidates,n);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
//     {
//         sort(candidates.begin(),candidates.end());
//         int n=candidates.size();
//         set<vector<int>> ans;vector<int> temp;
//         vector<vector<int>> fin;
//         help(0,target,ans,temp,candidates,n);
//         for (auto it:ans)
//         fin.push_back(it);
//         return fin;    
//     }
// };



//now moving to a more optimised code which works in O(2^n * k); Try to dry run on the given example with recursion tree and parameters to understand the code better



class Solution {
public:
    void help(int i,vector<int> arr,vector<int> &temp,vector<vector<int>> &ans,int target)
    {
        if (target==0)
        {
            ans.push_back(temp);
            return;
        }
        for (int ind=i;ind<arr.size();ind++)
        {
            if (ind>i and arr[ind]==arr[ind-1]) continue;
            if (arr[i]>target) break;
            temp.push_back(arr[ind]);
            help(ind+1,arr,temp,ans,target-arr[ind]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        help(0,candidates,temp,ans,target);
        return ans;
    }
};
