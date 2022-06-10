// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) 
    {
        sort(arr,arr+n);vector<long long> sum1,sum2;string s="";
        for (int i=0;i<n;i++)
        {
            if (i%2==0)
            sum1.push_back(arr[i]);
            else
            sum2.push_back(arr[i]);
        }
        long long k=max(sum1.size(),sum2.size());long long carr=0;
        if (sum1.size()>sum2.size())
        sum2.insert(sum2.begin(),0);
        for (long long i=k-1;i>=0;i--)
        {
            int m=sum1[i]+sum2[i]+carr;
            carr=m/10;
            int add=m%10;
            s=s+to_string(add);
        }
        if (carr>0)
        s=s+to_string(carr);
        reverse(s.begin(),s.end());
        while (s[0]=='0')
        {
            s.erase(s.begin());
        }
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
