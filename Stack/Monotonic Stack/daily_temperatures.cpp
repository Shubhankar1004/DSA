// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        stack<int> s;
        for(int i=0; i<n; i++){
            if(s.empty()) 
                s.push(i);
            else{
                if(temperatures[s.top()] >= temperatures[i]) 
                    s.push(i);
                else{
                    while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                        ans[s.top()] = i - s.top();
                        s.pop();
                    }
                    s.push(i);
                }
            }
        }
        return ans;
    }
};
