class Solution{
    public:
    
    Node* build(int preorder[],int prestart,int preend,int inorder[],int instart,int inend, unordered_map<int,int>&m)
    {
        if (prestart>preend || instart>inend)
        return NULL;
        Node* root=new Node(preorder[prestart]);
        
        int inroot=m[root->data];
        int numsleft=inroot-instart;
        
        root->left=build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,m);
        root->right=build(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,m);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,int>m;
        for (int i=0;i<n;i++)
        {
            m[in[i]]=i;
        }
        Node *root=build(pre,0,n-1,in,0,n-1,m);
        return root;
    }
};
