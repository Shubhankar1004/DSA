long long rob(int i,vector<int> &value,vector<long long> &dp)
{
    if (i==1)
    {
        return value[i];
    }
    if (i<1)
        return 0;
    if (dp[i]!=-1)
        return dp[i];
    long long chor=value[i]+rob(i-2,value,dp);
    long long nochor=rob(i-1,value,dp);
    return dp[i]=max(chor,nochor);
}

long long robs(int i,vector<int> &value,vector<long long> &dp)
{
    if (i==0)
    {
        return value[i];
    }
    if (i<0)
        return 0;
    if (dp[i]!=-1)
        return dp[i];
    long long chor=value[i]+robs(i-2,value,dp);
    long long nochor=robs(i-1,value,dp);
    return dp[i]=max(chor,nochor);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if (n==1)
        return valueInHouse[0];
    else if (n==2)
    {
        return max(valueInHouse[0],valueInHouse[1]);
    }
    else
    {
    vector<long long>dp(n,-1);
    long long ans1=rob(n-1,valueInHouse,dp);
    vector<long long>dp1(n,-1);
    long long ans2=robs(n-2,valueInHouse,dp1);
    return max(ans1,ans2);
    }
}
