// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int sumXor = nums[0];
        for(int i=1; i<nums.size(); i++) 
        {
            // the sum of two distinct numbers
            sumXor = sumXor ^ nums[i];
        }
        
        // to find rightmost set bit
        int rightMostBit = sumXor & ~(sumXor-1);
        
        int x = 0, y = 0;
        for(int i=0; i<nums.size(); i++) 
        {
            if(rightMostBit & nums[i]) 
            {
                // number which has set bit 1 corresponding to rightMostBit
                x = x ^ nums[i];
            }
            else {
                // number which has set bit 0 corresponding to rightMostBit
                y = y ^ nums[i];
            }
        }
        return {min(x, y), max(x, y)};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
