Node* insert(Node* root, int Key) 
{
    // Your code here
    if (root==NULL)
    return new Node(Key);
    Node *t=root;
    while(t->left || t->right)
    {
        if (Key==t->data)
        return root;
        if (Key>t->data)
        {
            if (t->right)
            t=t->right;
            else
            break;
        }
        else if(Key<t->data)
        {
            if (t->left)
            t=t->left;
            else
            break;
        }
    }
    if (Key>t->data)
    t->right=new Node(Key);
    if (Key<t->data)
    t->left=new Node(Key);
    return root;
}
