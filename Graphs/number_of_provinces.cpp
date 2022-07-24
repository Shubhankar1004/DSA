//converted adjacency matrix to adjacency list and applied dfs


class Solution {
  public:
    void dfs(int node,vector<int>list[],vector<int> &vis)
    {
        vis[node]=1;
        for (auto it:list[node])
        {
            if (!vis[it])
            dfs(it,list,vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        // code here
        vector<int>list[V+1];
        
        for (int i=0;i<V;i++)
        {
            for (int j=0;j<V;j++)
            {
                if (i!=j and adj[i][j]==1)
                list[i+1].push_back(j+1);
            }
        }
        vector<int>vis(V+1,0);
        int ans=0;
        for (int i=1;i<=V;i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i,list,vis);
            }
        }
        return ans;
    }
};
