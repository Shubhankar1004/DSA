// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* n, int& ans) {
        if(!n)
            return 0;
        
        int leftMax = dfs(n->left, ans);
        int rightMax = dfs(n->right, ans);
        leftMax = max(0, leftMax);
        rightMax = max(0, rightMax);
        
        ans = max(ans, n->val + leftMax + rightMax);
        
        return n->val + max(leftMax, rightMax);
    }
};
