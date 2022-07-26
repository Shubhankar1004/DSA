class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low<high)
        {
            int partpos=partition(arr,low,high);
            quickSort(arr,low,partpos-1);
            quickSort(arr,partpos+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int i=low;
       int j=high;
       int pivot=arr[i];
       while(i<j)
       {
           while(arr[i]<=pivot)
           i++;
           while(arr[j]>pivot)
           j--;
           if (i<j)
           {
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
            
       }
        int temp=arr[j];
        arr[j]=arr[low];
        arr[low]=temp;
       return j;
    }
};
