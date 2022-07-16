//using BFS

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


//using DFS


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(int node, vector<int>& vis,vector<int> adj[],int parent)
    {
        vis[node]=1;
        for (auto it:adj[node])
        {
            if (vis[it]==1)
            {
                if (it!=parent)
                return 1;
            }
            else if(cycle(it,vis,adj,node))
            return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        // code here
        vector<int>vis(V,0);
        for (int i=0;i<V;i++)
        {
            if (!vis[i])
            {
                if (cycle(i,vis,adj,-1))
                return 1;
            }
        }
        return 0;
        
    }
};
