// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    int findPeakElement(vector<int>& v) 
    {
        int low=0;
        int high=v.size()-1;int n=v.size();
        while (low<=high)
        {
            int mid=low+(high-low)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if (v[mid]>v[prev] && v[mid]>v[next])
            return v[mid];
            else if ((v[mid]>v[prev]) &&(v[mid]<v[next]))
            low=mid+1;
            else if ((v[mid]<v[prev]) &&(v[mid]>v[next]))
            high=mid-1;
        }
    }
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}

  // } Driver Code Ends
