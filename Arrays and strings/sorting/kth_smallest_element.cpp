//quick select algorithm


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void swap(int arr[],int i,int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    int partition(int arr[], int l, int r, int k)
    {
        int i = l-1;
        int pivot = arr[r];
        for(int j = l;j<r;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr,i,j);
            }
        }
        swap(arr,i+1,r);
        return i+1;
    }
    int kthSmallest(int arr[], int l, int r, int k) 
    {
        //code here
        
        int pivotpos=partition(arr,l,r,k);
        if (k-1==pivotpos)
        return arr[pivotpos];
        else if (k-1<pivotpos)
        return kthSmallest(arr,l,pivotpos-1,k);
        else if (k-1>pivotpos)
        return kthSmallest(arr,pivotpos+1,r,k);
        
    }
};
