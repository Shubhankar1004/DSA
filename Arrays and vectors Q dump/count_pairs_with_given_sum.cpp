//O(n)
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        unordered_map<int,int>m;int c=0;
        for (int i=0;i<n;i++)
        {
            
            m[arr[i]]++;
        }
        for (int i=0;i<n;i++)
        {
            if (arr[i]!=k-arr[i])
            c+=m[k-arr[i]];
            else
            c+=m[k-arr[i]]-1;
        }
        return (c/2);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends
