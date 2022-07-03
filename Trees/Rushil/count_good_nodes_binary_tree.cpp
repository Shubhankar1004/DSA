// https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode*& n, int maxVal){
        if(n==nullptr)
            return 0;
        
        int res = (n->val >= maxVal)? 1 : 0;
        maxVal = max(n->val, maxVal);
        res += dfs(n->left, maxVal);
        res += dfs(n->right, maxVal);
        
        return res;
    }
};
