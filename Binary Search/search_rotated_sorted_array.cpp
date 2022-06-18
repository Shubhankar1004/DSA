// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            cout << mid << endl;
            if(target == nums[mid])
                return mid;
            // if mid less than first element then we are in the right sorted portion
            else if(nums[mid] < nums[0]){
                // we are in right sorted portion and target is to the left
                if(target <= nums[mid])
                    high = mid - 1;
                // we are in right sorted portion and target is either to the right or present in the left sorted portion
                else{
                    // target is in the right sorted portion
                    if(target <= nums[n-1])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            // else go to left sorted portion
            else{
                // we are in left sorted portion and target is to the right
                if(target >= nums[mid])
                    low = mid + 1;
                // we are in left sorted portion and target is to the left or present in the right sorted portion
                else{
                    // target is in the left sorted portion
                    if(target >= nums[0])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }
        return -1;
    }
};
