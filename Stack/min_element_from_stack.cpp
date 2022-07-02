//O(n) space

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s,ss;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if (s.empty())
           return -1;
           return (ss.top());
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if (s.empty())
           return -1;
           int k=s.top();
           int f=ss.top();
           s.pop();
           if (k==f)
           {
               
               ss.pop();
           }
           return k;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if (ss.empty() || x<=ss.top())
           ss.push(x);
           s.push(x);
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends



//O(1) space


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if (s.empty())
           return -1;
           return (minEle);
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if (s.empty())
           return -1;
           int k=s.top();
           
           s.pop();
           if (k<=0)
           {
               
               int res = minEle;
               minEle = minEle-k;
               return res;
           }
           return k;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if (s.empty())
           {
               s.push(x);
               minEle=x;
           }
           else if (x<=minEle)
           {
               s.push(x-minEle);
               minEle=x;
           }
           else
           {
               s.push(x);
           }
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
