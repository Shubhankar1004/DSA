long long ninja(int day,vector<vector<int>> &points,int last,vector<vector<long long>> &dp)
{
    if (day==0)
    {
        int maxi=0;
        for (int i=0;i<=2;i++)
        {
            if (i!=last)
            {
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last]!=-1)
        return dp[day][last];
    int maxi=0;
    for (int i=0;i<=2;i++)
        {
            if (i!=last)
            {
                int score=points[day][i]+ninja(day-1,points,i,dp);
                maxi=max(maxi,score);
            }
            
        }
        return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<long long>>dp(n,vector<long long>(4,-1));
    long long ans=ninja(n-1,points,3,dp);
    return ans;
}
