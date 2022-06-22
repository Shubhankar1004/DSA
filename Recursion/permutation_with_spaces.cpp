// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:


    void perm(vector<string>&v,string s,string op)
    {
        if (s.length()==0)
        {
            v.push_back(op);
            return;
        }
        string op1=op;
        op1.push_back(s[0]);
        string op2=op;
        op2.push_back(' ');
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        perm(v,s,op1);
        perm(v,s,op2);
    
    }

    vector<string> permutation(string S)
    {
        vector<string>v;
        string op="";
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        perm(v,S,op);
        sort(v.begin(),v.end());
        return v;
        
        
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
