
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10]={4,7,1,8,2,5,4,9,6,3};
    // implements the quick select algorithm in O(n)
    // following code places the 9th element in the right position in case of a sorted array
    nth_element(a,a+8,a+10); //nth_element(iterator to first element, to nth element, to last element)
    nth_element(a,a+8,a+10,greater<int>()); //if the sorting is in the decreasing order
    for (int x:a)
    {
        cout<<x<<" ";
    }

    int a[10]={4,7,1,8,2,5,4,9,6,3};
    sort(a,a+10);
    reverse(a,a+10); // reverse funtion to reverse arrays of any type
    char s[]="hello world"; // wont work with a string - applicable only to character arrays
    reverse(s,s+strlen(s));
    cout<<s;
    
    // unique(iterator to first, to last) removes consecutive equal elements and returns iterator to end
    char c[]="abcccdddcccbba";
    int newlen = unique(s, s+ strlen(s))-s;
    s[newlen]=0;
    cout<<s; //abcdcba
    //to obtain distinct characters in the string first sort then apply unique
}
