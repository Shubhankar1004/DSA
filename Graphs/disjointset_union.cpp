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
};

int main()
{
    DisjointSet ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    ds.unionbyrank(5,6);
    //if 3 and 7 belong to same component or not
    if (ds.findUParent(3)==ds.findUParent(7)) return 1;
    ds.unionbyrank(3,7);

}
