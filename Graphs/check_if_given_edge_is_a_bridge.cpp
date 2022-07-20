//O(V+E) time and O(V) space

//checking if c-d edge is a bridge or not
public:
	void dfs( int node, vector<int> adj[], int c , int d,vector<int> &visited)
	{
	    visited[node] = true ; 
	    
	    for(auto nbr : adj[node])
	    {
	        if( !visited[nbr] && (node!=c || nbr != d) )
	        dfs(nbr, adj, c, d, visited ) ; 
	    }
	}
	
	
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> visited(V, false) ;
        dfs( c , adj , c, d , visited ) ;//send C as initial node 

        return !visited[d] ; 
    }
