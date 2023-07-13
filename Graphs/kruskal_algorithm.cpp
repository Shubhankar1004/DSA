//Kruskals algorithm using DSU

class DisjointSet
{
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for (int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findUParent(int node)
    {
        if (node==parent[node])
        return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionsize(int u,int v)
    {
        int up_u=findUParent(u);
        int up_v=findUParent(v);
        if (up_u==up_v) return;
        if (size[up_u]<size[up_v])
        {
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else if (size[up_v]<size[up_u])
        {
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        else
        {
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for (int i=0;i<V;i++)
        {
            for (auto it:adj[i])
            {
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int ans=0;
        for (auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if (ds.findUParent(u)!=ds.findUParent(v))
            {
                ds.unionsize(u,v);
                ans+=wt;
            }
        }
        return ans;
    }
};
