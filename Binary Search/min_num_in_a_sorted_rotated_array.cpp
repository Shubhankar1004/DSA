// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
     {   
       int minEle=INT_MAX;
       while(low<=high){
           int mid=(low+high)/2;
           if(arr[mid]>=arr[low]){//this half is sorted and its low can be minimum so far
               minEle=min(minEle,arr[low]);
               low=mid+1;
           }
           else if(arr[mid]<=arr[high]){//right half is sorted
               minEle=min(minEle,arr[mid]);
               high=mid-1;
           }
       }
       return minEle;
   }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends





// if you also need the index of the sorted part which you can use to tell how many rotations the array had got use the following code

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
     {   
       int minEle=INT_MAX;int index=0;
       while(low<=high){
           int mid=(low+high)/2;
           if(arr[mid]>=arr[low])
           {//this half is sorted and its low can be minimum so far
               if (arr[low]<minEle)
               {
                   minEle=arr[low];
                   index =low;
               }
               low=mid+1;
           }
           else if(arr[mid]<=arr[high])
           {//right half is sorted
               if (arr[mid]<minEle)
               {
                   minEle=arr[mid];
                   index =mid;
               }
               high=mid-1;
           }
       }
       cout<<index;
       return minEle;
   }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends
