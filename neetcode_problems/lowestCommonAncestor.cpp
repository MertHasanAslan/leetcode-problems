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

// ikisi de solda ve ya ikisi de sağdaysa oraya geç
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) { return root; }
        
        if (dfs(root->left, p) && dfs(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        } 
        if (dfs(root->right, p) && dfs(root->right, q)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;

    }

    bool dfs(TreeNode* node, TreeNode* target){
        if (!node) { return false; }
        if (node == target) { return true; }

        return dfs(node->left, target) || dfs(node->right, target);
    }


};
