//using dfs



 class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle(int node,vector<int>&vis,vector<int>&dfsvis,vector<int>adj[])
    {
        vis[node]=1;
        dfsvis[node]=1;
        for (auto it:adj[node])
        {
            if (!vis[it])
            {
                if (cycle(it,vis,dfsvis,adj))
                return 1;
                //dfsvis[it]=0;
            }
            else if (dfsvis[it]==1)
            {
                return 1;
            }
           
        }
         dfsvis[node]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // code here
        vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        for (int i=0;i<V;i++)
        {
            if (!vis[i])
            {
                if (cycle(i,vis,dfsvis,adj))
                return 1;;
            }
        }
        return 0;
    }
};
