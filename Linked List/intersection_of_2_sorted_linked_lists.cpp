Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *t1=head1,*t2=head2;
    Node *head3,*z;int k=0;
    while (t1!=NULL and t2!=NULL)
    {
        if (t1->data < t2->data)
        t1=t1->next;
        else if (t1->data > t2->data)
        t2=t2->next;
        else
        {
            if (k==0)
            {
                k=1;
                Node *f=new Node(t1->data);
                head3=f;
                z=head3;
            }
            else
            {
                Node *f=new Node(t1->data);
                z->next=f;
                z=z->next;
            }
            t1=t1->next;
            t2=t2->next;
            
        }
    }
    return head3;
}
