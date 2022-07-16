//using dfs


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void topo(int node,vector<int> &vis,vector<int> adj[],stack<int> &st)
	{
	    vis[node]=1;
	    for (auto it: adj[node])
	    {
	        if (!vis[it])
	        {
	            topo(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V,0);
	    stack<int>st;
	    for (int i=0;i<V;i++)
	    {
	        if (!vis[i])
	        {
	            topo(i,vis,adj,st);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty())
	    {
	        int k=st.top();
	        ans.push_back(k);
	        st.pop();
	    }
	    return ans;
	}
};



//using bfs : Kahns algorithm


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>in(V,0);
	    vector<int>ans;
	    queue<int>q;
	    for (int i=0;i<V;i++)
	    {
	        for (auto it:adj[i])
	        {
	            in[it]++;
	        }
	    }
	    for (int i=0;i<V;i++)
	    {
	        if (in[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int node =q.front();
	        q.pop();
	        ans.push_back(node);
	        for (auto it:adj[node])
	        {
	            in[it]--;
	            if (in[it]==0)
	            q.push(it);
	        }
	        
	    }
	    return ans;
	    
	}
};
