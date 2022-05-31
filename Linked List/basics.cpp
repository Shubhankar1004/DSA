#include <iostream>
using namespace std;

//Creating Node Structure
struct Node{
 int data;
 Node *link;
};
//creating head pointer and equating to NULL
Node *head=NULL;

//Main Method
int main()
{
 //Creating a new Node
 Node *ptr=new Node();
 //Adding data and setting link to NULL
 ptr->data=2;
 ptr->link=NULL;
 //Pointing head to created Node
 head=ptr;
 cout<<"data is"<<head->data;
 return 0;
}