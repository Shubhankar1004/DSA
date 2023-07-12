class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});//wt,node
        vector<int> vis(V,0);
        //vis[0]=1;
        int sum=0;
        while(!pq.empty())
        {
            auto node=pq.top().second;
            auto wt=pq.top().first;
            pq.pop();
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            for (auto it:adj[node])
            {
                if (!vis[it[0]])
                {
                    pq.push({it[1],it[0]});
                }
            }
        }
        return sum;
    }
};
