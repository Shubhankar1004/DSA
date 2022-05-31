// implements the quick select algorithm in O(n)
// following code places the 9th element in the right position in case of a sorted array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10]={4,7,1,8,2,5,4,9,6,3};
    nth_element(a,a+8,a+10); //nth_element(iterator to first element, to nth element, to last element)
    nth_element(a,a+8,a+10,greater<int>()); //if the sorting is in the decreasing order
    for (int x:a)
    {
        cout<<x<<" ";
    }
}