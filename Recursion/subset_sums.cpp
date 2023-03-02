//print sum of all subsets in array

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>v;int sum=0;
        //vector<int>out;
        comb(0,sum,arr,N,v);
        return v;
    }
    
    void comb(int i,int sum,vector<int>arr,int n,vector<int>&v)
    {
        if (i==n)
        {
            v.push_back(sum);
            return;
        }
        comb(i+1,sum+arr[i],arr,n,v);
        comb(i+1,sum,arr,n,v);
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
