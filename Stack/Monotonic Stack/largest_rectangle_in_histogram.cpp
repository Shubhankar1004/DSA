// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int> > s; // index, height pairs
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int idx = -1;
            while(!s.empty() && s.top().second > heights[i]){
                idx = s.top().first;
                maxArea = max(maxArea, (i - idx) * s.top().second);
                s.pop();
            }
            if(idx != -1)
                s.push(make_pair(idx, heights[i]));
            else
                s.push(make_pair(i, heights[i]));
        }
        while(!s.empty()){
            // cout << s.top().first << " " << s.top().second << endl;
            maxArea = max(maxArea, (n-s.top().first)*s.top().second);
            s.pop();
        }
        return maxArea;
    }
};