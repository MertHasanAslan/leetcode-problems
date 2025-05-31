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

    int depth(TreeNode* node){
        if (node==nullptr){ return 0; }
        return (max(depth(node->left), depth(node->right)) +1);
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){ return true; }
        int left = depth(root->left);
        int right = depth(root->right);

        return abs(right-left) < 2 && isBalanced(root->left) && isBalanced(root->right); //check every level 
    }
};