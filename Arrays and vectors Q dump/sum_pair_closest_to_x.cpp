//O(n)
//Given a sorted array arr[] of size N and a number X, find a pair in array whose sum is closest to X.


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        int n=(int)arr.size();
        vector<int>v;int low=0,high=n-1,l=0,r=0;
        int diff=INT_MAX;
        while(low<high)
        {
            if (abs(arr[low]+arr[high]-x)<diff)
            {
                diff=abs(arr[low]+arr[high]-x);
                l=arr[low];
                r=arr[high];
            }
            if (arr[low]+arr[high]<x)
            {
                low++;
            }
            else if (arr[low]+arr[high]>x)
            {
                high--;
            }
            else if (arr[low]+arr[high]==x)
            {
                l=arr[low];
                r=arr[high];
                break;
            }
            else{}
            
        }
        v.push_back(l);
        v.push_back(r);
        return v;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
