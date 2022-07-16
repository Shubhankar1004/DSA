
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfshelp(int node,vector<int>& vis,vector<int> adj[],vector<int> &dfs)
    {
        dfs.push_back(node);
        vis[node]=1;
        for (auto it:adj[node])
        {
            if (!vis[it])
            {
                //dfs.push_back(it);
                //vis[it]=1;
                dfshelp(it,vis,adj,dfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int>dfs;
        vector<int>vis(V,0);
        for (int i=0;i<V;i++)
        {
            if (!vis[i])
            {
                dfshelp(i,vis,adj,dfs);
            }
        }
        return dfs;
    }
};



