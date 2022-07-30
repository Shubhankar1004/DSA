class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        // Your code here
        long long cost=0;
        if (n==1)
        return 0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(long long i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        while(pq.size()!=1)
        {
            long long x=pq.top();pq.pop();
            long long y=pq.top();pq.pop();
            x+=y;
            pq.push(x);
            cost+=x;
        }
        return cost;
    }
};
