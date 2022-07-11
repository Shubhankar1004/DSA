class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) 
    {
        // code here
        if (root==NULL)
        return;
        mirror(root->left);
        mirror(root->right);
        
        if (root->left ||root->right)
        {
            Node *t=root->left;
            root->left=root->right;
            root->right=t;
        }
        /*if (root->right)
        {
            Node *t=root->right;
            root->right=root->left;
            root->left=t;
        }*/
 
    }
};
