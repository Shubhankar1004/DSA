class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int ,long long > mp;
        
        long long mx=1;
        for(auto ele : tasks )
        {
            if(mp.find(ele)!=mp.end())
                mx=std::max(mp[ele]+space+1ll,mx);
            //cout << ele << " " << mx << "\n";
            mp[ele]=mx;
            mx++;
        }
        
        return mx-1;
    }
};
