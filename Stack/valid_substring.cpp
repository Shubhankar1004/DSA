// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) 
    {
        stack<int> stack;
        stack.push(-1);
        int result = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                stack.push(i);
            }
            else{
                stack.pop();
                
                if(not stack.empty()){
                    result = max(result, i-stack.top());
                }
                else{
                    stack.push(i);
                }
            }
        }
        
        return result;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
