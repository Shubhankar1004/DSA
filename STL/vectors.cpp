#include <bits/stdc++.h>
using namespace std;

bool decre(int x, int y)
{
    return (x>y);
}

int main()
{
    vector<int> a = {11,2,3,14};
    cout<<a[2]<<endl;

    int n = 100;
    vector<int> aa(n,0); // initialize a vector of size n with all elements zero


    sort(a.begin(),a.end()); //O(Nlog(N))
    for (int x:a)
    {
        cout<<x<<" ";
    }cout<<endl;

    //use comparator function as argument to sort in decreasing order
    // sort(a.begin(),a.end(),decre); //O(Nlog(N))
    sort(a.begin(),a.end(),greater<int>()); //O(Nlog(N))

    for (int x:a)
    {
        cout<<x<<" ";
    }cout<<endl;


    // vector should be sorted in increasing order to use this
    sort(a.begin(),a.end()); //O(Nlog(N))
    
    bool ispresent = binary_search(a.begin(),a.end(),3);// true (returns 1)
    // O(log(N))
    cout<<ispresent<<endl;// 1

    ispresent = binary_search(a.begin(),a.end(),10);// false (returns 0)
    // O(log(N))
    cout<<ispresent<<endl;// 0


    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(123);
    // 2,3,11,14,100,100,100,100,100,123


    // works efficiently on sorted vector
    vector<int>::iterator it1 = lower_bound(a.begin(),a.end(),100);
    // returns iterator of first number in vector >= given argument

    auto it2 = upper_bound(a.begin(),a.end(),100);
    // returns iterator of first number in vector > given argument
    // return iterator of a.end() if no number > given aug is present

    cout<<*it1<<" "<<*it2<<endl;
    cout<< it2 - it1 <<endl; // 5 (frequency of the number, 100)


    for (int x:a) //original vector
    {
        cout<<x<<" ";
    }cout<<endl;

    for (int x:a) // values changed while being passed by value
    {
        x++;
        cout<<x<<" ";
    }cout<<endl;

    for (int x:a) // original vector to show values not changed
    {
        cout<<x<<" ";
    }cout<<endl;

    for (int &x:a) // values changed while being passed by refrence
    {
        x++;
        cout<<x<<" ";
    }cout<<endl;

    for (int x:a) // original vector to show values are changed
    {
        cout<<x<<" ";
    }cout<<endl;
<<<<<<< HEAD


    //for 2d vector
    int n,m;
    cin>>n>>m;int b;
    vector<vector<int>> a(n,vector<int>(m));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>b;
            a.push_back(b);
        }
    }

=======
    
    // If you're facing error while accessing vector elements
    //Use
    cout<<a.at(0)<<endl;
    //instead of a[0]
    // at() checks availability of element before accessing
>>>>>>> f22e7ca1d58ae555299aa5564f00d71cacaf9e93
}
