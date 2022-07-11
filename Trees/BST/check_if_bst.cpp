class Solution
{
    public:
    //int flag=1;int maxie=INT_MIN,minie=INT_MAX;
    //Function to check whether a Binary Tree is BST or not.
    bool BST(Node* root,int maxie,int minie)
    {
        if (!root)
        return 1;
        if (root->data>maxie || root->data<minie)
        return 0;
        
        return (BST(root->left,root->data,minie) && BST(root->right,maxie,root->data));
        
    }
    bool isBST(Node* root) 
    {
        // Your code here
        return BST(root,INT_MAX,INT_MIN);
        //return flag;
    }
};
