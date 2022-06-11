//Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
//Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
//Note: All occurrences of every character in str1 should map to the same character in str2

// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n=str1.length();int m=str2.length();
        if (n!=m)
        return 0;
        else
        {
            unordered_map<char,char>m,k;
            for (int i=0;i<n;i++)
            {
                if (m.find(str1[i])==m.end())
                m[str1[i]]=str2[i];
                if (k.find(str2[i])==k.end())
                k[str2[i]]=str1[i];
                if (m.find(str1[i])!=m.end()||k.find(str2[i])!=k.end())
                {
                    if ((m[str1[i]]!=str2[i])||(k[str2[i]]!=str1[i]))
                    return 0;
                }
            }
            return 1;
        }
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends
