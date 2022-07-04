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


//using level order traversal



class Solution{
  public:
    // function should return level of the target node
    int getLevel(struct Node *node, int target)
    {
    	//code here
    	queue<Node*>q;
    	int level=0;int ans=0;
    	q.push(node);
    	while (!q.empty())
    	{
    	    level++;
    	    int c=q.size();
    	    while(c--)
    	    {
    	        Node *t=q.front();
    	        if (t->data==target)
    	        ans=level;
    	        if (t->left)
    	        q.push(t->left);
    	        if (t->right)
    	        q.push(t->right);
    	        q.pop();
    	    }
    	    //level++;
    	}
    	return ans;
    }
};

