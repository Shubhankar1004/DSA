#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-10);
    // automatically gets sorted when each element is inserted in log(N) time complexity

    for (int x:s)
        cout<<x<<" ";
    cout<<endl;


    // -10, -1, 1, 2
    auto it = s.find(1);

    if (it == s.end()) // returns iterator of s.end() if number given is not in set
        cout<<"not present\n";
    else
        cout<<"present "<<*it<<endl;

    
    auto it1 = s.lower_bound(-1);// same as vector, ie >=
    auto it2 = s.upper_bound(-1);// same as vector, ie >, if given aug is not present, it2 == s.end()
    cout<<*it1<<" "<<*it2<<endl;

    auto itt = s.begin();
    // to increment the iterator by 'n', use the advance function
    // advance(iterator, n) this means iterator+=n
    advance(itt,1);
    cout<<*itt<<endl;
}
