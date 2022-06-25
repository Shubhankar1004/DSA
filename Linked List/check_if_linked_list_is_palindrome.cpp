// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
     Node* middle(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* mid)
    {
        
    Node *p,*c,*n;
    p=NULL;
    c=mid;
    while(c!=NULL)
    {

        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    mid=p;
    return mid;
    }
    
    //Function to check if the linked list has a loop.
    bool isPalindrome(Node* head)
    {
        // your code here
        if (head==NULL)
        return true;
        Node *mid=middle(head);
        Node *last=reverse(mid);
        while(last!=NULL)
        {
            if (head->data!=last->data)
            return false;
            head=head->next;
            last=last->next;
        }
        return 1;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
