class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
         
        for (auto it:points)
        {
            int x=it[0];
            int y=it[1];
            int dist=x*x+y*y;
            pq.push({dist,{x,y}});
            if (pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            auto it=pq.top();
            vector<int>temp;
            temp.push_back(it.second.first);
            temp.push_back(it.second.second);
            ans.push_back(temp);
            temp.clear();
            pq.pop();
        }
        return ans;
    }
};
