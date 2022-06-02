// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
    
        int i=0,j=0;int sum1=0,sum2=0,sum=0;
        while (i<l1 && j<l2)
        {
            if (A[i]>B[j])
            {
                sum2+=B[j];j++;
            }
            else if (A[i]<B[j])
            {
                sum1+=A[i];i++;
                
            }
            else
            {
                sum+=max(sum1,sum2)+A[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
            
        }
        while (i<l1)
        {
            sum1+=A[i];i++;
        }
        while (j<l2)
        {
            sum2+=B[j];j++;
        }
        sum+=max(sum1,sum2);
        return sum;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends
