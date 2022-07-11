class Solution{
    public:
    int m=0;
    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        // code here 
        if (node==NULL)
        return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        m=max(m,max(lh,rh)+1);
        return(1+max(lh,rh));
    }
};
