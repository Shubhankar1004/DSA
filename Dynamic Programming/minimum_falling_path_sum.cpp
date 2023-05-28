//memoization soln

// class Solution {
// public:
//     int memo(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
//         if(j<0 || j>(matrix.size()-1))return 1e9;
//         if(i==0) return matrix[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=memo(i-1,j,matrix,dp);
//         int ld=memo(i-1,j-1,matrix,dp);
//         int rd=memo(i-1,j+1,matrix,dp);
//         return dp[i][j]=matrix[i][j]+min(up,min(ld,rd));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int mini=INT_MAX;
//         for(int i=0;i<n;i++){
//             vector<vector<int>> dp(n,vector<int>(n,-1));
//             int sum=memo(n-1,i,matrix,dp);
//             mini=min(mini,sum);
//         }
//         return mini;
//     }
// };


//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }  
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int ld=INT_MAX,u=INT_MAX,rd=INT_MAX;
                if (i>0 and j>0 )ld=dp[i-1][j-1];
                if (i>0 and j>=0)u=dp[i-1][j];
                if (i>0 and j<n-1)rd=dp[i-1][j+1];
                dp[i][j]=min(ld,min(u,rd))+matrix[i][j];
            }
        }  
        int mini=INT_MAX;
        for (int i=0;i<n;i++)
        {
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};


