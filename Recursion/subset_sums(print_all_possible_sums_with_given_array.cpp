//print sum of all subsets in array

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>v;int sum=0;
        //vector<int>out;
        comb(0,sum,arr,N,v);
        return v;
    }
    
    void comb(int i,int sum,vector<int>arr,int n,vector<int>&v)
    {
        if (i==n)
        {
            v.push_back(sum);
            return;
        }
        comb(i+1,sum+arr[i],arr,n,v);
        comb(i+1,sum,arr,n,v);
        
    }
};

