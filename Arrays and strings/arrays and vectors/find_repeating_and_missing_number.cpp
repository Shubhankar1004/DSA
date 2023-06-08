//in O(n) time and O(1) space

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int x,y;
        int s=0,s2=0,sn2=0;int n=nums.size();
        for (int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            s2+=(nums[i]*nums[i]);
            sn2+=((i+1)*(i+1));
        }    
        int sn=(n*(n+1))/2;
        int a = s-sn;
        int b = s2-sn2;
        b=b/a;
        x=(a+b)/2;
        y=(b-1)/2;
        // x is the repeating number and y is the missing number. Check copy for peoof
        return x;
    }
};
