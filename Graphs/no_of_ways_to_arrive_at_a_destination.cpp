class Solution {
public:
    int countPaths(int n, vector<vector<int>>& a) {
        vector<pair<long long, long long>> adj[n];
        // it -> from to weight
        for(auto it:a){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; // dist node
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long wt = it.second;
                long long adjnode = it.first;
                if(d + wt < dist[adjnode]){
                    dist[adjnode] = d + wt;
                    ways[adjnode] = ways[node];
                    pq.push({ dist[adjnode], adjnode});
                }
                else if(d + wt == dist[adjnode])
                         ways[adjnode]=((ways[adjnode] % 1000000007 + ways[node]) % 1000000007) % 1000000007;
            }
        }
        return ways[n - 1] % 1000000007;
    }
};
