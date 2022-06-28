// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
   {
       // code here
       // return head of reversed list
       struct Node *next,*prev,*current;
       prev=NULL;
       current =head;
       while(current!=NULL)
       {
           next=current->next;
           current ->next=prev;
           prev=current;
           current=next;
           
       }
       head=prev;
       return head;
   }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here8
        int s=0,sum=0,c=0;Node *res,*fin,*t;
        first=reverseList(first);
        second=reverseList(second);
        s=first->data+second->data;
        sum=s%10;
        res=new Node(sum);
        c=s/10;
        fin=res;//t=res;
        first=first->next;
        second=second->next;
        
        while(first!=NULL && second !=NULL)
        {
            s=first->data+second->data+c;
            sum=s%10;
            t=new Node(sum);
            res->next=t;
            c=s/10;
            first=first->next;
            second=second->next;
            res=res->next;
        }
        while (first!=NULL)
        {
            t=new Node((c+first->data)%10);res->next=t;
            c=(c+first->data)/10;
            first=first->next;
            res=res->next;
        }
        while (second!=NULL)
        {
            t=new Node((c+second->data)%10);res->next=t;
            c=(c+second->data)/10;
            second=second->next;
            res=res->next;
        }
        if (c!=0)
        {
            t=new Node(c);res->next=t;
        }
        fin=reverseList(fin);
        return fin;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
