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
    int dia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) { return 0; }

        findDia(root);
        return dia;
    }

    int findDia(TreeNode* node){
        if (node == nullptr) { return 0; }

        int left = findDia(node->left);
        int right = findDia(node->right);
        
        dia = max(dia, left + right);
        return max(left, right) +1;

    }
};
