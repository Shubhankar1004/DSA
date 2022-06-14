// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        vector<int>p(n,0);unordered_map<int,int>m;
        p[0]=arr[0];int ans=0;
        m[p[0]]++;
        for (int i=1;i<n;i++)
        {
            p[i]=p[i-1]+arr[i];
            m[p[i]]++;
            if (m[p[i]]>1 || p[i]==0)
            ans=1;
        }
        return ans;
        
        //if in the prefix sum array a number occurs twice then it means beech me kahi sum 0 hua hoga isiliye wapas wahi number prefix array me aaya
        
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends