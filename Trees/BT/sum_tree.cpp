class Solution
{
    public:
    int flag=1;
    int sum(Node *root)
    {
        if (root==NULL)
        return 0;
        int ls=sum(root->left);
        int rs=sum(root->right);
        if (root->left && root->right)
        {
            if (ls+rs != root->data)
            flag=0;
        }
        
        return(ls+rs+root->data);
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         sum(root);
         return flag;
    }
};
