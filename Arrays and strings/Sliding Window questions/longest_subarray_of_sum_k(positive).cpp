// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int i=0,j=0,sum=0,ans=0;
        while (j<N)
        {
            sum+=A[j];   
            if (sum<K)
            {
                
                j++;
            }
            else if(sum==K)
            {
                if (j-i+1>ans)
                ans=j-i+1;
                sum-=A[i];
                i++;
                j++;
                
            }
            else
            {
                sum-=A[i];
                i++;
            }
        }
        return ans;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
