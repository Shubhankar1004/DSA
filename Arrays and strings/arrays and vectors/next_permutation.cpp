/*

    Time Complexity : O(N), Since we traverse the entire Array(nums) once in the worst case. Where N = size of
    the Array(nums).

    Space Complexity : O(1), Constant Space

    This has an algorithm which needs to be followed
    Traversing from the back
    1) find index 1 such that a[i]<a[i+1]
    traversing from the back again
    2) find index 2 st a[index2]>a[index1]
    3)swap nums[index1],nums[index2]
    4) reverse the array starting from index1 + 1 and print

*/


/***************************************** Approach 1 First Code *****************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};






/***************************************** Approach 2 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};



*****************************************/

