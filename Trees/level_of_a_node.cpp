//using DFS (recursive method)

class Solution{
  public:
    // function should return level of the target node
    
    void lev(Node *root,int target,int &rank,int level)
    {
        if (root==NULL)
        return;
        if (root->data==target)
        {
            rank=level;
            return;
        }
        lev(root->left,target,rank,level+1);
        lev(root->right,target,rank,level+1);
    }
    int getLevel(struct Node *node, int target)
    {
    	//code here
    	int rank=0;
    	lev(node,target,rank,1);
    	return rank;
    }
};
