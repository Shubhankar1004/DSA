class Solution
{
    public:
    int flag=-1,i=0;
    void kth(Node *root,int K)
    {
        if (root==NULL)
        return;
        kthLargest(root->right,K);
        ++i;
        if (K==i)
        flag=(root->data);
        kthLargest(root->left,K);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        kth(root,K);
        return flag;
    }
};
