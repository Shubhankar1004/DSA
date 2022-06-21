//all possible subsets of a string


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string S)
		{
		    vector<string>v;
		    string op="";
		    comb(S,op,v);
		    sort(v.begin(),v.end());
		    v.erase(v.begin()+0);
		    return v;
		}
		
		void comb(string s,string op,vector<string>&v)
		{
		    if (s.length()==0)
		    {
		        v.push_back(op);
		        return;
		    }
		    string op1=op;
		    string op2=op;
		    op2.push_back(s[0]);
		    s.erase(s.begin()+0);
		    comb(s,op1,v);
		    comb(s,op2,v);
		
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
