#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ways of intialization
    pair<int,int>p{1,1};
    pair<string,int>pp;
    pp.first = "hello";
    pp.second = 2;

    //pairs like vectors can be directly compared using comparators

    //vector of pairs can be directly sorted
    vector<pair<string,int>> v{{"Sowon",173},{"Yerin",167},{"Eunha",163}}; //direct initialization of vector of pairs
    v.emplace_back("hello",55); //to push back a pair into a vector use emplace_back
    sort(v.begin(),v.end());
    for (auto &x:v)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

}