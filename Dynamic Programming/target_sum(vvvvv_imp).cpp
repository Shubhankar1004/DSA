//the following soln is just a recursive one and not dp bcoz when you memoize this code it introduces negative indices whis is an issue
 

// class Solution {
// public:
//     int help(int i,int target,vector<int> nums, vector<vector<int>> &dp)
//     {
//         if (i==0)
//         {
//             if (nums[i]==target)
//             return 1;
//             else if (nums[i]==-target)
//             return 1;
//             else return 0;
//         }
//         //if (dp[i][target]!=-1)
//         //return dp[i][target];
//         int positive=nums[i]+help(i-1,target-nums[i],nums,dp);
//         int negative= -nums[i]+help(i-1,target+nums[i],nums,dp);
//         return positive+negative;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) 
//     {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return help(n-1,target,nums,dp);    
//     }
// };


// to counter negative indices in dp, you can use map, see the


 class Solution {
public:
    int helper(vector<int>& nums, int n, int target, unordered_map<string, int> &m) {
        if (n == 0) {
            return target == 0;
        }
        
        string key = to_string(n) + "*" + to_string(target);
        if (m.find(key) != m.end()) {
            return m[key];
        }
        
        return m[key] = helper(nums, n-1, target - nums[n-1], m) +
                        helper(nums, n-1, target + nums[n-1], m);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> m;
        return helper(nums, nums.size(), target, m);
    }
};
