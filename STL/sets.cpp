#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-10);
    s.insert(-10);//only one -10 in inserted in to the set
    // automatically gets sorted when each element is inserted in log(N) time complexity
    
    cout<<*s.begin()<<endl;//-10
    cout<<*s.end()<<endl;//2

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
    
    set<int, greater<int> > s1;//decreasing order set
    
    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());
    
    // remove all elements up to 30 in s2
    s2.erase(s2.begin(), s2.find(30));
}
