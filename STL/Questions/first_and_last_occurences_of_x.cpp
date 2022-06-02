//in O(log n) time
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int low=0,high=n-1,mid=0;vector<int>v;int ans =0;
    while (low<=high)
    {
        mid=low + (high-low)/2;
        if (arr[mid]==x)
        {
            ans =mid;
            high=mid-1;      // if multiple numbers occur and we want the lower index of that number of multiple occurence then bring down high and store mid 
        }
        else if(arr[mid]<x)
        low=mid+1;
        else
        high=mid-1;
        
    }
    if (arr[ans]==x)
    v.push_back(ans);
    else
    v.push_back(-1);
    low=0;high=n-1;mid=0;ans=0;
    while (low<=high)
    {
        mid=low + (high-low)/2;
        if (arr[mid]==x)
        {
            ans=mid;
            low=mid+1;   // similar to bringing down high coz now we want higher index
        }
        else if(arr[mid]<x)
        low=mid+1;
        else
        high=mid-1;
        
    }
    if (arr[ans]==x)
    v.push_back(ans);
    else
    v.push_back(-1);
    return v;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
