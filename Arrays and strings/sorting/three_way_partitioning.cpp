//in time O(n) and space O(1)


class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    
    
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        int s = 0, e = array.size()-1;
       for(int i = 0; i<=e; i++)
       {
           if(array[i]<a) swap(array[i],array[s++]);
           else if(array[i]>b) swap(array[i--],array[e--]);
       }
        
    }
};
