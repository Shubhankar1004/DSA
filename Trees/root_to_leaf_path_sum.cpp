class Solution
{
    public:
    bool hasPathSum(Node *root, int S) 
    {
        // Your code here
        if(root == NULL)
        return false;
        
        S -= root->data;
        if(root->left == NULL and root->right == NULL)
        { // leaf
            if(S == 0)return true ; 
            else return false ;
        }
        if(hasPathSum(root->left,S) == true)return true ;
        if(hasPathSum(root->right,S) == true)return true;
        
        return false;
    }
};
