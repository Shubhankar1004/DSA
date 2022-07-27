//merge sort application


class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    //ans+=m-i+1, means that all the elements that follow the element which satisfies the 
    //condition of swap will also contribute to the possible pairs of answers 
    typedef long long ll;
 ll ans=0;
   
   
void merge(ll arr[], ll l, ll m, ll r)
   {
       ll i=l, j=m+1, k=l;
       ll temp[r+1];
       
       while(i<=m && j<=r){
       if(arr[i]<=arr[j]){
           temp[k] = arr[i];
           k++;
           i++;
       }
       else{
           temp[k] = arr[j];
           k++;
           j++;
           ans+=m-i+1;
       }
   }
   while(i<=m){
       temp[k] = arr[i];
       k++;
       i++;
   }
   
   while(j<=r){
       temp[k]=arr[j];
       j++;
       k++;
   }
       
       for(ll i=l; i<=r; i++){
           arr[i]=temp[i];
       }
   }
   public:
   void mergeSort(ll arr[], ll l, ll r)
   {
     if(l<r){
         ll m=(l+r)/2;
         mergeSort(arr, l, m);
         mergeSort(arr, m+1, r);
         merge(arr, l, m, r);
     }
   }
   long long int inversionCount(long long arr[], long long n)
   { ans=0;
       mergeSort(arr,0, n-1);
     return ans;
   }

};
