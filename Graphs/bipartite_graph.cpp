//using bfs

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    // Code here
	    int flag=1;
	    vector<int>col(V,-1);
	    for (int i=0;i<V;i++)
	    {
	        if (col[i]==-1)
	        {
	            queue<int>q;
	            q.push(i);
	            col[i]=0;
	            while (!q.empty())
	            {
	                int node=q.front();
	                q.pop();
	                for (auto it:adj[node])
	                {
	                    if (col[it]==-1)
	                    {
	                        if (col[node]==0)
	                        col[it]=1;
	                        else
	                        col[it]=0;
	                        q.push(it);
	                    }
	                    else 
	                    {
	                        if (col[it]==col[node])
	                        {
	                            flag=0;
	                            break;
	                        }
	                    }
	                    
	                }
	            }
	            
	        }
	    }
	    return flag;
	}

};


//using dfs


bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}
