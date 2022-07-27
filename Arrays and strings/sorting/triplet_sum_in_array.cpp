//my code which works in O(n2) but requires auxiliary space


class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int ans=0;
        unordered_map<int,int>m;
        for (int j=0;j<n;j++)
        {
            
            m[A[j]]=j;
        }
        for (int i=0;i<n;i++)
        {
            int f=X-A[i];
            m.erase(A[i]);
            for (int k=0;k<n;k++)
            {
                if (k!=i)
                {
                    if (m.find(f-A[k])!=m.end() && m.find(f-A[k])->second!=k)
                    ans=1;
                }
            }
            m[A[i]]=i;
        }
        return ans;
    }

};


// optimised code using binary search concept and works inplace


class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
   {
       sort(A,A+n);
       
       for(int i=0;i<n;i++)
       {
           int low=i+1,high=n-1;
           while(low<high)
           {
               int ans=A[i]+A[low]+A[high];
               if(ans==X)
               {
                   return 1;
               }
               else
               if(ans>X)
               {
                   high--;
               }
               else
               if(ans<X)
               {
                   low++;
               }
           }
       }
       return 0;
   }

};
