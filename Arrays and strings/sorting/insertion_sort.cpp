class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
        int value=arr[i];
        int hole=i;
        while (hole>0 && arr[hole-1]>value)
        {
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for (int i=1;i<n;i++)
        {
            insert(arr,i);
        }
    }
};
