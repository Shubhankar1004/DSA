/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     void pre(Node *root,vector<int>&v)
    {
        if (root==NULL)
            return;
         
         v.push_back(root->val);
        
        for (auto child : root->children)
            pre(child,v);
        
        
    }
    vector<int> preorder(Node* root) 
    {
        vector<int>v;
        pre(root,v);
        return v;
    }
};




class Solution {
public:
    
    void post(Node *root,vector<int>&v)
    {
        if (root==NULL)
            return;
        
        for (auto child : root->children)
            post(child,v);
        
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) 
    {
        vector<int>v;
        post(root,v);
        return v;
    }
};
