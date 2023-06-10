// //Memoization
// //Time complexity:O(n∗n)
// //Space complexity:O(n∗n)+O(n)

// class Solution {
// public:
// int help(int i,int prev_i,vector<int> &nums,vector<vector<int>> &dp)
// {
//     if (i==nums.size())
//     return 0;
//     if (dp[i][prev_i+1]!=-1) //we use prev_i + 1 bcoz prev_i is initially -1 and hence and as negative indices cannot be stored we use 1 based indexing for prev_i
//     return dp[i][prev_i+1];
//     int maxi=help(i+1,prev_i,nums,dp);
//     if (prev_i == -1 || nums[i]>nums[prev_i])
//     maxi=max(maxi,1+help(i+1,i,nums,dp));
//     return dp[i][prev_i+1]=maxi;
// }
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));// we use n * n+1 matrix -> n+1 for prev_i coz we have a 1 based indexing for it as initially prev_i is -1 
//         return help(0,-1,nums,dp);
//     }
// };


//Tabulation
//TC O(n*n) SC O(n*n)

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         // for (int i=0;i<=n;i++)   not req as we have made everything on the dp = 0
//         // dp[n][i]=0;
//         for (int i=n-1;i>=0;i--)
//         {
//             for (int prev_i=i-1;prev_i>=-1;prev_i--)
//             {
//                 int maxi=dp[i+1][prev_i+1];
//                 if (prev_i == -1 || nums[i]>nums[prev_i])
//                 maxi=max(maxi,1+dp[i+1][i+1]);
//                 dp[i][prev_i+1]=maxi;
//             }
//         }
//         return dp[0][0];
//     }
// };




//Another approach - DAA Paper approach
//non DP approach



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,1);
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (nums[j]<nums[i])
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int maxi=0;
        for (int i=0;i<n;i++)
        maxi=max(maxi,dp[i]);
        return maxi;
    }
};
