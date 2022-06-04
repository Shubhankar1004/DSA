//Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.
//unique approach


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int sum=0; long long count=0;
       unordered_map<int,int> umap;
       for(int i=0;i<n;i++){
           if(arr[i]==0) arr[i]=-1;
       }
       for(int i=0;i<n;i++){
           sum+=arr[i];
           umap[sum]++;
           if(sum==0) count+= umap[sum];
           else count += umap[sum]-1;
       }
       return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends
