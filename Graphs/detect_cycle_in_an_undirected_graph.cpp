class Solution {
  public:
  int flag=0;
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if (!vis[i])
            {
                queue<pair<int,int>>q;
                q.push({i,-1});
                vis[i]=1;
                while(!q.empty())
                {
                    auto it=q.front();
                    int node=it.first;
                    int parent=it.second;
                    q.pop();
                    for(auto k:adj[node])
                    {
                        if(!vis[k])
                        {
                            q.push({k,node});
                            vis[k]=1;
                        }
                        else
                        {
                            if (k!=parent)
                            flag=1;
                        }
                    }
                }
            }
        }
        return flag;
    }
};
