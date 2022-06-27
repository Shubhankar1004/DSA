// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
        
        bool left = dfs(root->left, p);
        bool right = dfs(root->right, q);
        
        // if p is not in left and q is not in right, then p is in right and q is in left
        // if p is in left and q is in right, the root is the answer
        if(!left && !right || left && right)
            return root;
        
        if(left)
            return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
    bool dfs(TreeNode *root, TreeNode *v){
        if(root == nullptr)
            return false;
        
        if(root == v)
            return true;
        
        return dfs(root->left, v) || dfs(root->right, v);
    }
};
