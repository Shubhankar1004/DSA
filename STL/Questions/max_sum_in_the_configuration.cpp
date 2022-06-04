//Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.
//O(n)
//unique approach


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int sum=0;int d=0;int max=0;
    for (int i=0;i<N;i++)
    {
        sum+=A[i]*i;
        d+=A[i];
    }
    max=sum;
    for (int i=0;i<N;i++)
    {
        sum=sum+d-N*A[N-i-1];
        if (sum>max)
        max=sum;
    }
    
    return max;
    
}
