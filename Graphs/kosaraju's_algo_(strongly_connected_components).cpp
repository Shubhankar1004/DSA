//overall time complexity of O(V+E)

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &s)
	{
	    vis[node]=1;
	    for (auto it : adj[node])
	    {
	        if (!vis[it])
	        dfs(it,vis,adj,s);
	    }
	    s.push(node);
	}
	void dfsrec(vector<int> adj[], int k, vector<int>&vis)
    {
        vis[k]=1;
        
        for(int x : adj[k])
        {
            if(!vis[x])
            {
                dfsrec(adj, x, vis);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>vis(V,0);
        stack<int>s;int ans=0;
        for (int i=0;i<V;i++)
        {
            if (!vis[i])
            dfs(i,vis,adj,s);
        }
        vector<int>trans[V];
        
        for(int i = 0; i < V; i++)
        {
            vis[i]=0;
            for(int x : adj[i])
            {
                trans[x].push_back(i);
            }
        }
        while(!s.empty())
        {
            int i = s.top();
            s.pop();
            if(vis[i] == 0)
            {
                ans++;
                dfsrec(trans, i, vis);
            }
        }
        return ans;
    }
};
