class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> dpf(n,1);
	    vector<int> dpb(n,1);
	    for (int i=1;i<n;i++)
	    {
	        for (int j=0;j<i;j++)
	        {
	            if (nums[i]>nums[j] and dpf[i]<1+dpf[j])
	            {
	                dpf[i]=1+dpf[j];
	            }
	        }
	    }
	    reverse(nums.begin(),nums.end());
	    for (int i=1;i<n;i++)
	    {
	        for (int j=0;j<i;j++)
	        {
	            if (nums[i]>nums[j] and dpb[i]<1+dpb[j])
	            {
	                dpb[i]=1+dpb[j];
	            }
	        }
	    }
	    reverse(dpb.begin(),dpb.end());
	    int maxi=0;
	    for (int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dpf[i]+dpb[i]-1);
	    }
	    return maxi;
	}
};
