// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int ans=0;int mask=1;
        if (m==n)
        return -1;
        while (m!=0 && n!=0)
        {
            ans++;
            int x=m&mask;int y=n&mask;
            if (x != y)
            return ans;
            m=m>>1;
            n=n>>1;
        }
        while (m!=0)
        {
            ans++;
            int x=m&mask;
            if ((x)==1)
            return ans;
            m=m>>1;
        }
        while(n!=0)
        {
            ans++;
            int x=n&mask;
            if ((x)==1)
            return ans;
            n=n>>1;
        }
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}   // } Driver Code Ends
