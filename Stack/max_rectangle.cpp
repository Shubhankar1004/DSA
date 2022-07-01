// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long area=0;
        stack<pair<long long,long long>>s;
        vector<long long>v1;
        for (int i=0;i<n;i++)
        {
            if (s.empty())
            v1.push_back(-1);
            else if(s.top().first<arr[i])
            v1.push_back(s.top().second);
            else if(s.top().first>=arr[i])
            {
                while(!s.empty()&&s.top().first>=arr[i])
                s.pop();
                if (!s.empty())
                v1.push_back(s.top().second);
                else
                v1.push_back(-1);
            }
            else{}
            s.push({arr[i],i});
        }
        vector<long long>v2;
         stack<pair<long long,long long>>s1;
         for (int i=n-1;i>=0;i--)
        {
            if (s1.empty())
            v2.push_back(n);
            else if(s1.top().first<arr[i])
            v2.push_back(s1.top().second);
            else if(s1.top().first>=arr[i])
            {
                while(!s1.empty()&&s1.top().first>=arr[i])
                s1.pop();
                if (!s1.empty())
                v2.push_back(s1.top().second);
                else
                v2.push_back(n);
            }
            else{}
            s1.push({arr[i],i});
        }
        reverse(v2.begin(),v2.end());
        for (int i=0;i<n;i++)
        {
           if ((v2[i]-v1[i]-1)*arr[i]>area)
           area=(v2[i]-v1[i]-1)*arr[i];
        }
        return area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        // Your code here
        
        long long arr[m] = {0} ;
        for(int i=0;i<m;i++)
        {
            arr[i] = M[0][i];
            //cout<<arr[i]<<" ";
        }
        //cout<<endl;
        int res = getMaxArea(arr,m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1)
                {
                    // M[i][j] += M[i-1][j];
                    arr[j] += M[i][j];
                }
                else
                {
                    //M[i][j] = 0;
                    arr[j] = 0;
                }
                     
                
                //cout<<arr[j]<<" ";
                
            }
            //cout<<endl;
            int temp = getMaxArea(arr,m);
            res = max(temp,res);
            //cout<< res << endl ;
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
