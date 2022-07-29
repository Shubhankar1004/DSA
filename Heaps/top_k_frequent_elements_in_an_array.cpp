class Solution {
  public:
     static bool cmp(pair<int,int> a ,pair<int,int> b)
{
if(a.first == b.first)
return a.second > b.second;

else
return a.first > b.first;
}


   vector<int> topK(vector<int>& nums, int k) {
       // Code here
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
       }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
       for(auto i=mp.begin();i!=mp.end();i++){
           minH.push({i->second,i->first});
           if(minH.size()>k){
               minH.pop();
           }
       }
       vector<pair<int,int>>ans;
       while(!minH.empty()){
           ans.push_back(minH.top());
           minH.pop();
       }
       sort(ans.begin(),ans.end(),cmp);
       vector<int>res;
       for(int i=0;i<k;i++){
           res.push_back(ans[i].second);
       }
       return res;
   }
};
