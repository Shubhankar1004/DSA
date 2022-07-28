//given an array of lengths, batao kitne triangle ban sakte hai

//chal raha hai code but not optimised

class Solution
{
    public:
    //Function to count the number of possible triangles.
    int tri(int a,int b,int c)
    {
        if (a+b>c and a+c>b and b+c>a)
        return 1;
        else
        return 0;
    }
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        int ans=0;
        for (int i=0;i<n-2;i++)
        {
            for (int j=i+1;j<n-1;j++)
            {
                int sum=arr[i]+arr[j];
                for (int k=n-1;k>j;k--)
                {
                    if (sum>arr[k])
                    {
                        ans=ans+k-j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

//optimised using 2 pointer algo in O(n2)

class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        int ans=0;
        sort(arr,arr+n,greater<int> ());
        for(int i=0;i<n-2;i++){
            int largerSide = arr[i];
            int l=i+1,r=n-1;
            while(l<r){
                if(arr[l]+arr[r]>largerSide){
                    ans+=r-l;
                    l++;
                }
                else
                    r--;
            }
        }
        return ans;
    }
};
