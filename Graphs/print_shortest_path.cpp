class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for (auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1,0);
        for(int i=0;i<parent.size();i++)
        parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty())
        {
            auto node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for (auto it:adj[node])
            {
                if (dist[node]+it.second<dist[it.first])
                {
                    dist[it.first]=dist[node]+it.second;
                    pq.push({dist[it.first],it.first});
                    parent[it.first]=node;
                    
                }
            }
        }
        if (dist[n]==1e9) return {-1};
        vector<int> path;
        int node=n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};
