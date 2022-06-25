//https://leetcode.com/problems/find-the-duplicate-number/
// Floyd's Cycle detection algorithm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = nums.size();
        int slow = 0, fast = 0;
        // Phase 1 of algorithm
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if(slow == fast)
                break;
        }
        int slow2 = 0;
        // Phase 2 of algorithm
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2)
                break;
        }
        
        return slow;
    }
};
