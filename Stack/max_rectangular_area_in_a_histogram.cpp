// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long area=0;
        stack<pair<long long,long long>>s;
        vector<long long>v1;
        for (int i=0;i<n;i++)
        {
            if (s.empty())
            v1.push_back(-1);
            else if(s.top().first<arr[i])
            v1.push_back(s.top().second);
            else if(s.top().first>=arr[i])
            {
                while(!s.empty()&&s.top().first>=arr[i])
                s.pop();
                if (!s.empty())
                v1.push_back(s.top().second);
                else
                v1.push_back(-1);
            }
            else{}
            s.push({arr[i],i});
        }
        vector<long long>v2;
         stack<pair<long long,long long>>s1;
         for (int i=n-1;i>=0;i--)
        {
            if (s1.empty())
            v2.push_back(n);
            else if(s1.top().first<arr[i])
            v2.push_back(s1.top().second);
            else if(s1.top().first>=arr[i])
            {
                while(!s1.empty()&&s1.top().first>=arr[i])
                s1.pop();
                if (!s1.empty())
                v2.push_back(s1.top().second);
                else
                v2.push_back(n);
            }
            else{}
            s1.push({arr[i],i});
        }
        reverse(v2.begin(),v2.end());
        for (int i=0;i<n;i++)
        {
           if ((v2[i]-v1[i]-1)*arr[i]>area)
           area=(v2[i]-v1[i]-1)*arr[i];
        }
        return area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
