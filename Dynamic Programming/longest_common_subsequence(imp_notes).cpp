//In kanpsack and subsequence questions we used to do take or not take and here we do match or not match

//following is the memoized code but it gives TLE if we dont use & with string text1 and string text2. If not then the code runs fine
// class Solution {
// public:
//     int help(int i,int j,vector<vector<int>> &dp,string &text1,string &text2)
//     {
//         if (i<0 || j<0) //if 1 string is only over then match kya karega -> 0 return kar
//         return 0;
//         if (dp[i][j]!=-1)
//         return dp[i][j];
//         if (text1[i]==text2[j])   //if characters match then add 1 and call with i-1 and j-1
//         return dp[i][j]=1+help(i-1,j-1,dp,text1,text2);
//         else  //if char dont match then take the max of matching i-1 with j or j-1 with i
//         {
//             return dp[i][j]=max(help(i-1,j,dp,text1,text2),help(i,j-1,dp,text1,text2));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) 
//     {
//         vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
//         return help(text1.size()-1,text2.size()-1,dp,text1,text2);  
//     }
// };

//TABULATION 

class Solution {
public:
int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        int m=text1.size();int n=text2.size();
        for (int i=0;i<m;i++)
        dp[i][0]=0;
        for (int i=0;i<n;i++)
        dp[0][i]=0;

        for (int i=1;i<=m;i++) //Understand why this goes till m and n -> beacause in base case we cant have negative indices hence we make 0 as base case and follow a 1 based indexing for storing in dp whereas access elements in text1 and text 2 normally.
        {
            for (int j=1;j<=n;j++)
            {
                if (text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};



//Now for printing this longest subsequence:
//Construct theirr dp table and traverse from right bottom to left up, always slecting those index that are giving max 
//dp[i][j] and adding the letter to answer vector when s[i]==t[j]
//For Example input s=abcde t=bdgek
//DP Table will be
//     a b c d e
//   0 0 0 0 0 0
// b 0 0 0 0 0 0
// d 0 1 1 1 1 1
// g 0 1 1 1 1 1
// e 0 1 2 2 2 2
// k 0 1 2 2 3 3


//start with 5,5 i.e. i=m,j=n;
while (i>0 and j>0)
{
    if (s[i-1] == t[j-1])
        ans.push_back(s[i-1]);i--;j--;
    else if (dp[i-1][j]>dp[j][j-1])
    {
          i=i-1;
    }
    else if (dp[i][j-1]>dp[i-1][j])
    {
        j=j-1;
    }
    reverse(ans.begin(),ans.end()); return ans;
}
