// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        long long low = 1, high = *max_element(piles.begin(), piles.end()), k = 0;
        long long ans = 0;
        bool firstOccurance = true;
        while(low > 0 && low <= high){
            k = low + (high-low)/2;
            long long val = 0;
            for(int i=0; i<n; i++){
                if(piles[i] % k == 0)
                    val += piles[i] / k;
                else
                    val += piles[i] / k + 1;
            }
            if(val <= (long long)h){
                ans = k;
                if(firstOccurance){
                    high = k-1;
                }
                else{
                    low = k+1;
                }
            }
            else
                low = k + 1;
        }
        return ans;
    }
};
