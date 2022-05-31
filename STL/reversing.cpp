#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10]={4,7,1,8,2,5,4,9,6,3};
    sort(a,a+10);
    reverse(a,a+10); // reverse funtion to reverse arrays of any type
    char s[]="hello world"; // wont work with a string - applicable only to character arrays
    reverse(s,s+strlen(s));
    cout<<s;
}
