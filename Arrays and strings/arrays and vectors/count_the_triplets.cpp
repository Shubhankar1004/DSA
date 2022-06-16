//Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    unordered_map<int,int>m;int ans=0;
	    for (int i=0;i<n;i++)
	    {
	        m[arr[i]]=i;
	    }
	    for (int i=0;i<n-1;i++)
	    {
	        for (int j=i+1;j<n;j++)
	        {
	            if (m.find(arr[i]+arr[j])!=m.end()&& m[arr[i]+arr[j]]!=i&& m[arr[i]+arr[j]]!=j)
	            ans++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends
