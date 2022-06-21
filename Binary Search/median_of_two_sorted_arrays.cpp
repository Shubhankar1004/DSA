// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> &A = nums1, &B = nums2;
        if(m > n){
            swap(A, B);
            swap(m, n);
        }
        
        int l=0, r=m-1;
        int half = (m+n)/2;
        double ans = 0.0;
        // Binary search on smaller array 
        while(true){
            int i = l+(r-l)/2;
            i = (l+r>=0)? i: i-1;
            int j = half - i - 2;
            
            int Aleft, Aright, Bleft, Bright;
            Aleft = (i>=0)? A[i] : -1e7;
            Aright = (i+1<m)? A[i+1] : 1e7;
            Bleft = (j>=0)? B[j] : -1e7;
            Bright = (j+1<n)? B[j+1] : 1e7;
            
            // check if partition is correctly made
            if(Aleft <= Bright && Bleft <= Aright){
                // odd length
                if((m+n)&1)
                    ans = min(Aright, Bright);
                else
                    ans = (max(Aleft, Bleft) + min(Aright, Bright))/2.0;
                return ans;
            }
            else if(Aleft > Bright)
                r = i-1;
            else
                l = i+1;
        }
        return ans;
    }
};
