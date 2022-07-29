//works in O(nlogk)

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K)
    {
        // Your code here
        vector<int>v;
        priority_queue<int,vector<int>,greater<int>>minh;
        for (int i=0;i<num;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>K)
            {
                v.push_back(minh.top());
                minh.pop();
            }
        }
        while(!minh.empty())
        {
            v.push_back(minh.top());
            minh.pop();
        }
        return v;
    }
};
