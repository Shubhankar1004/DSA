// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        long long int mod=1e9+7;
        long long int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || (i==j))
                {
                    dp[i][j]=1;
                }
                else
                {
                   dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
            }
        }
       vector<long long int > a;
        for(int i=0;i<n;i++)
        {
            a.push_back(dp[n-1][i]);
        }
        return a;
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends
