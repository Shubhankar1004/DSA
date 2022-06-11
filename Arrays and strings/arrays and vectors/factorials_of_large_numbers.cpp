// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N)
    {
        vector<int>v;v.push_back(1);int carr=0;
        for (int i=2;i<=N;i++)
        {
            carr=0;
            for (int j=0;j<(int)v.size();j++)
            {
                int val=v[j]*i+carr;
                v[j]=val%10;
                carr=val/10;
            }
            while (carr>0)
            {
                v.push_back(carr%10);
                carr/=10;
            }
            
        }
        reverse(v.begin(),v.end());
            return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
