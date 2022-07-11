class Solution{
  public:
    /*You are required to complete this method*/
    int ht=0;
    int minDepth(Node *root) 
    {
        // Your code here
        if (root==NULL)
        return INT_MAX;
        if(root -> right == NULL && root -> left == NULL)  
        return 1;
        int lt=minDepth(root->left);
        int rt=minDepth(root->right);
        //ht=min(lt,rt)+1;
        return (min(lt,rt)+1);
    }
};
