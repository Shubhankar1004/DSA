#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    s+='e';// faster than s=s+e as s+=e works in O(1) while the other in O(n)
    s+="abccddf";
    //s.substr(index,length)
    
    cout<<s.substr(1,3);

    string a="abcdef";
    reverse(a.begin(),a.end());//fedcba

    string a="abcdef";
    reverse(a.begin()+2,a.end()+5);//adcbef

    string a="shubhankar";
    sort(a.begin(),a.end());
}

