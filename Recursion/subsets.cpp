//subset, power set and subsequence are the same thing with some diff(copy) while sub array and substring is a different thing


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>>v;
        vector<int>op;
        subset(v,A,op);
        sort(v.begin(),v.end());
        return v;
    }
    
    void subset(vector<vector<int>>&v,vector<int> A,vector<int>op)
    {
        if (A.empty())
        {
            v.push_back(op);
            return;
        }
        vector<int>op1(op);
        vector<int>op2(op);
        op2.push_back(A[0]);
        A.erase(A.begin()+0);
        subset(v,A,op1);
        subset(v,A,op2);
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends
