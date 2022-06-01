#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;

    // m[key] = value;
    m[1] = 100;
    m[2] = 12;
    m[23] = -1;
    m[143143] = 22; // O(log(N)) time taken to store one value in map
    //m[1]=200 - if key already exists then the value is updated


    // example where map is used to calculate freq of letters in a string
    map<char, int> count;
    string s = "qwerty hello rahul";

    for (char c:s)
    {
        count[c]++; // O(klog(N)), where k is length of string and log(N) is time for each initialization
        // N = number of keys present in map at time of initialization
    }
    cout<<count['e']<<" "<<count['z']<<endl;


    // Different ways of printing map contents
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    for (auto x : m) // better universal way
    {
        cout<<x.first<<" "<<x.second<<endl;
    }


    unordered_map<char, int> u;
    // everything same as normal map
    // just the difference that unordered map uses hashing to insert or delete 
    // and nuormal map uses BST, hence unordered map takes O(1) time for insert and delete,
    // whereas ordered map takes O(log(N))
    // Hence unordered-map is FASTER
}
