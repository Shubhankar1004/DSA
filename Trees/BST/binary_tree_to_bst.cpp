class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int> v;
    int i = 0;
    void in(Node* root) {
        if(!root) return;
        in(root->left);
        v.push_back(root->data);
        in(root->right);
    }
    void ans(Node* root) {
        if(!root) return;
        ans(root->left);
        root->data = v[i++];
        ans(root->right);
    }
    Node *binaryTreeToBST (Node *root)
    {
        in(root);
        sort(v.begin(), v.end());
        ans(root);
        return root;
    }
};
