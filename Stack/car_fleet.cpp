// https://leetcode.com/problems/car-fleet/

class Solution {
public:
    static bool compare(const pair<int,int>& t1, const pair<int,int>& t2){
        return (t1.first > t2.first);
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int> > cars(n);
        for(int i=0; i<n; i++){
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        sort(cars.begin(), cars.end(), compare);
        
        long long t1 = 0, t2 = 0;
        stack<pair<int, int> > s;
        for(int i=0; i<n; i++){
            if(s.empty()){
                // cout << cars[i].first << endl;
                s.push(cars[i]);
                continue;
            }
            pair<int, int> p = s.top();
            t1 = (long long)(target - p.first) * cars[i].second;
            t2 = (long long)(target - cars[i].first) * p.second;
            cout << t1 << t2 << endl;
            if(t1 < t2){
                s.push(cars[i]);
                // cout << cars[i].first << endl;
            }
        }
        return (int)(s.size());
    }
};
