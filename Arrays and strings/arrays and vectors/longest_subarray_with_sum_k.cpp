class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int sum=0;
        unordered_map<int,int> mp;int maxi=0;
        for (int i=0;i<N;i++)
        {
            sum+=A[i];
            if (sum==K)
            maxi=max(maxi,i+1);
            if (mp.find(sum)==mp.end())
            mp[sum]=i;
            int x=sum-K;
            if (mp.find(x)!=mp.end())
            {
                maxi=max(maxi,abs(i-mp[x]));
            }
        }
        
        return maxi;
    } 

};
