Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   Node *t=root;
   //cout<<(t->data)<<end;
   if (n2<n1)
   {
       int k=n1;
       n1=n2;
       n2=k;
   }
   while(1)
   {
       if (((t->data) >=n1) && ((t->data)<=n2))
       break;
       else if (t->data<n1 )
       {
           t=t->right;
       }
       else if (t->data>n2)
       {
           t=t->left;
       }
       else{}
   }
   return t;
}
