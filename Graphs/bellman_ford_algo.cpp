//time complexity of O(VE) and space of O(V). doesnt work for negative weight cycles.

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) 
    {
        // Code here
        vector<int>dist(V,1e8);
        dist[S]=0;
        for (int i=0;i<V-1;i++)
        {
            vector<int>temp;
            int u,v,wt;
            for (int j=0;j<adj.size();j++)
            {
                temp=adj[j];
                u=temp[0];
                v=temp[1];
                wt=temp[2];
                if (dist[u]+wt<dist[v])
                dist[v]=dist[u]+wt;
            }
        }
        return dist;
    }
};
