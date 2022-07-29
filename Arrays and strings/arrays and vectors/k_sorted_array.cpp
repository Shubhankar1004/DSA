//in such an array, the number which should be ideally in an index if sorted should only be k places away from that index in the given array


class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        vector<pair<int,int>>v;
        for (int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        for (int i=0;i<n;i++)
        {
            if (abs(v[i].second-i)>k)
            return "No";
        }
        return "Yes";
    }
};
