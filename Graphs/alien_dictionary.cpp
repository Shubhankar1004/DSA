class Solution{
    public:
    string findOrder(string dict[], int N, int K) 
    {
        //code here
        unordered_map<char,int> m;
        unordered_map<int,char> m1;
        int count=0;
        for(char i='a';i<='z';i++)
        {
            m1[count]=i;
            m[i]=count++;
        }
        vector<int> adj[K];
        for (int i=0;i<N-1;i++)
        {
            string w1=dict[i];
            string w2=dict[i+1];
            for (int j=0;j<min(w1.size(),w2.size());j++)
            {
                if (w1[j]!=w2[j])
                {
                    adj[m[w1[j]]].push_back(m[w2[j]]);
                    break;
                }
            }
        }
        vector<int> in(K,0);
        for (int i=0;i<K;i++)
        {
            for (auto it:adj[i])
            {
                in[it]++;
            }
        }
        queue<int> q;
        for (int i=0;i<K;i++)
        {
            if (in[i]==0)
            q.push(i);
        }
        string ans;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            ans+=m1[node];
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
