// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    set<string>ans;
		    int i=0;
		    perm(ans,S,i);
		    //sort(ans.begin(),ans.end());
		    vector<string>v(ans.begin(),ans.end());
		    //unique(ans.begin(),ans.end());
		    return v;
		}
		
		void perm(set<string>&ans,string s,int ind)
		{
		    if (ind==s.length())
		    {
		        ans.insert(s);
		        return;
		    }
		    for (int i=ind;i<s.length();i++)
		    {
		        swap(s[i],s[ind]);
		        perm(ans,s,ind+1);
		        swap(s[i],s[ind]);
		        
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends




//easier way using next_permutation(v.begin(),v.end()) which returns a bool value 1 if next permutation greater than previous one is possible and stores the permutation
//irrespective of bool returned in the particular vector




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(), S.end());
     vector<string> v;
     v.push_back(S);
     while(next_permutation(S.begin(), S.end()))
     {
         v.push_back(S);
     }
     return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
