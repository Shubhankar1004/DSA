class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int tmp[r-l+1];
         
         int i = l;
         int j = m+1;
         int k = 0;
         while(i<=m and j<=r)
         {
             if(arr[i]<=arr[j])
                tmp[k++] = arr[i++];
             else
                tmp[k++] = arr[j++];
         }
         
         while(i<=m) tmp[k++] = arr[i++];
         while(j<=r) tmp[k++] = arr[j++];
         
         for(int i =0; i < r-l+1; i++)
            arr[l+i] = tmp[i];
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            
            merge(arr,l,mid,r);
        }
    }
};
