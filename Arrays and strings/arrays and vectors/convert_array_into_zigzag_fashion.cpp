// lite hai question - dekhne ki zaroorat nahi


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) 
	{
	    if (arr[0]>arr[1])
	    {
	        int t=arr[0];
	        arr[0]=arr[1];
	        arr[1]=t;
	    }
	    for (int i=1;i<n-1;i++)
	    {
	        if (i%2==1)
	        {
	            if (arr[i]<arr[i+1])
	            {
	                int t=arr[i];
	                arr[i]=arr[i+1];
	                arr[i+1]=t;
	            }
	        }
	        else
	        {
	           if (arr[i]>arr[i+1])
	            {
	                int t=arr[i];
	                arr[i]=arr[i+1];
	                arr[i+1]=t;
	            } 
	        }
	    }
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
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
