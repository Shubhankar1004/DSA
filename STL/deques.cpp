#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq{4,5,6};
    dq.push_front(3);//O(1)
    dq.push_back(7);//O(1) and random access to any element also in O(1)
    cout<<dq[2]<<endl;//5
    dq.pop_front();
    cout<<dq[2]<<endl;//6

    //for a queue push_back becomes push and pop_front becomes pop
    //for stack push_back becomes push and pop_back becomes pop and back becomes top

    //priority queue - implementation of max heap
    priority_queue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    cout<<pq.top()<<endl;//3 - top returns greatest element
    pq.pop();//pops the greatest element
    cout<<pq.top()<<endl;//2

}