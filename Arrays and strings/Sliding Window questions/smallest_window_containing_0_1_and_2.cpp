// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) 
    {
        int i=0,j=0;unordered_map<char,int>m;int ans=INT_MAX;
        while (j<S.length())
        {
             m[S[j]]++;
            if (m.size()<3)
            {
               
                j++;
            }
            else if (m.size()==3)
            {
                int k=m['0']+m['1']+m['2'];
                ans=min(ans,k);
                m[S[i]]--;
                if (m[S[i]]==0)
                m.erase(S[i]);
                i++;
                m[S[j]]--;
            }
            
        }
        if (ans==INT_MAX)
        return -1;
        else return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends
