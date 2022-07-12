class Solution
{
    public:
    Node *prev=NULL;
    
    void flatten(Node *root)
    {
        //code here
        if (root==NULL)
        return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};


//using stack


class Solution
{
    public:
    Node *prev=NULL;
    
    void flatten(Node *root)
    {
        //code here
        stack<Node*>st;
        st.push(root);
        while(!st.empty())
        {
            Node *curr=st.top();
            st.pop();
            if (curr->right)
            st.push(curr->right);
            if (curr->left)
            st.push(curr->left);
            
            if (!st.empty())
            curr->right=st.top();
            curr->left=NULL;
        }
    }
};


//using morris in O(1) space

class Solution
{
    public:
    //Node *curr=NULL;
    
    void flatten(Node *root)
    {
        //code here
        Node *curr=root,*prev=NULL;
        while(curr!=NULL)
        {
            if (curr->left!=NULL)
            {
                prev=curr->left;
                while(prev->right)
                prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
