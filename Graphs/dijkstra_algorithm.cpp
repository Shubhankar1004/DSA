//minimum distance in weighted undirected graphs
//time : O((V+E)(log V)) and space : O(V) + O(V)
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dis(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[S]=0;
        pq.push({0,S});
        //vector<int>ans;
        while(!pq.empty())
        {
            int prev=pq.top().second;
            int prevdis=pq.top().first;
            pq.pop();
            for (auto it:adj[prev])
            {
                int next=it[0];
                int nextdis=it[1];
                if (dis[prev]+nextdis<dis[next])
                {
                    dis[next]=dis[prev]+nextdis;
                    pq.push({dis[next],next});
                }
            }
        }
        return dis;
    }
};
