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
    int result = 0;
    int goodNodes(TreeNode* root) {
        if (!root) { return 0; }
        dfs(root, root->val);
        return result;
    }


    void dfs(TreeNode* node, int max_val){
        if (!node) { return; }
        if (node->val >= max_val) { 
            result++;
            dfs(node->left, node->val);
            dfs(node->right, node->val);
        }
        else{
            dfs(node->left, max_val);
            dfs(node->right, max_val);
        }

    }
};