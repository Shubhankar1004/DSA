// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) 
    {
        long long res=0;int i=0;
        while (i<=31)
        {
            if (X&1 == 1)
            {
                res=res<<1;
                res=res | 1;
                
            }
            else
            {
                res=res<<1;
                res=res | 0;
                
            }
            X=X>>1;
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends
