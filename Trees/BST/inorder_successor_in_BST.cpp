class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *k=NULL;
    int f=0;
    void in(Node *root,Node *x)
    {
        if (root==NULL)
        return;
        in(root->left,x);
        if (f==1)
        {
            k=root;
            f=0;
        }
        if (root==x)
        {
            f=1;
        }
        
        
        
        in(root->right,x);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        in(root,x);
        return k;
        
    }
};


//optimised soln in time O(height) and space O(1)


class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *succ=NULL;
        while(root!=NULL)
        {
            if (root->data<x->data)
            {
                root=root->right;
            }
            else if (root->data>x->data)
            {
                succ=root;
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
        return succ;
    }
};
