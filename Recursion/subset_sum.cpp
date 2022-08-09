void subset(int i,vector<int> &ds,int s,int sum,int arr[],int n)
{
    if (i==n)
    {
        if (s==sum)
        {
            for (auto it:ds)
              cout<<it;
        }
        return;
    }
    ds.push_back(arr[i]);
    s+=arr[i];
    subset(i+1,ds,s,sum,arr,n);
    ds.pop_back();
    s-=arr[i];
    subset(i+1,ds,s,sum,arr,n);
}
