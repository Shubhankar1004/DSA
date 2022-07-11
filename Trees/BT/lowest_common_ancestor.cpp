class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if (root==NULL || root->data==n1 || root->data==n2)
       return root;
       
       Node *leftr=lca(root->left,n1,n2);
       Node *rightr=lca(root->right,n1,n2);
       if (leftr==NULL)
       return rightr;
       else if(rightr==NULL)
       return leftr;
       else
       return root;
    }
};
