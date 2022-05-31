#include <iostream>
using namespace std;

//Creating Node Structure
struct Node{
 int data;
 Node *link;
};
//creating head pointer and equating to NULL
Node *head=NULL;

//Function to Display middle element
void showMid()
{
  Node *slow=head;
  Node *fast=head;

  if(head==NULL)
   cout<<"List is Empty";
  else
  {
   while(fast!=NULL && fast->link!=NULL)
   {
    slow=slow->link;
    fast=fast->link->link;
   }
   cout<<"Middle element is:"<<slow->data;
  }

}

//Function to insert at the end of linked list
void insertEnd (int d)
{

 Node *ptr = new Node();
 ptr->data=d;
 ptr->link=NULL;

 if(head==NULL)
 head=ptr;
 else
 {
  Node *temp = head;
  while(temp->link != NULL)
  {
   temp=temp->link;
  }
  temp->link=ptr;

 }

}

//Main Function
int main()
{
 insertEnd(2);
 insertEnd(9);
 insertEnd(1);
 insertEnd(3);
 insertEnd(7);

 showMid();
 return 0;
}