// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) 
    {
        int i=0,j=0,ans=0;unordered_map<char,int>m;
        while (j<S.length())
        {
            m[S[j]]++;
            if (j-i+1<K)
            j++;
            else if (j-i+1==K)
            {
                if (m.size()==K-1)
                ans++;
                if (m.find(S[i])!=m.end())
                {
                    if(m[S[i]]==1)
                    m.erase(S[i]);
                    else
                    m[S[i]]--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
