class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool sub(Node *a,Node *b)
    {
        if(!a && !b) return true;
        
        if(!a || !b) return false;
        
        bool l = sub(a->left, b->left);
        bool r = sub(a->right, b->right);
        
        return (l && r && (a->data == b->data));
    }
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
         if (T==NULL && S!=NULL)
        return false;
        
        if (T->data==S->data && sub(S,T))
        {
            return true;
        }
        return (isSubTree(T->left,S)|| isSubTree(T->right,S));
        
        
    }
};
