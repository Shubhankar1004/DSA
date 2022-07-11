//left view

void left(Node *root,int lev,vector<int>&v)
{
    if (root==NULL)
    return;
    if (v.size()==lev)
    v.push_back(root->data);
    left(root->left,lev+1,v);
    left(root->right,lev+1,v);
}
vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int>v;
   left(root,0,v);
   return v;
}


//right view



class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void right(Node *root,int lev,vector<int>&v)
{
    if (root==NULL)
    return;
    if (v.size()==lev)
    v.push_back(root->data);
    right(root->right,lev+1,v);
    right(root->left,lev+1,v);
}
    vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int>v;
        right(root,0,v);
        return v;
    }
};
