Class DisjointSet
{
    vector<int> rank,parent;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for (int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findUParent(int node)
    {
        if (parent[node]==node)
        return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int up_u=findUParent(u);
        int up_v=findUParent(v);
        if (up_u==up_v) return;
        if (rank[up_u]<rank[up_v])
        {
            parent[up_u]=up_v;
        }
        else if(rank[up_v]<rank[up_u])
        {
            parent[up_v]=up_u;
        }
        else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }
}
