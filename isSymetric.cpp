#include <iostream>

using namespace std;

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

 class TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 }

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) { return true; } //if root is a leaf node, return true
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right){ //helper function
        if (left == nullptr && right == nullptr) { return true; } //if they are both nullptr, return true
        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)) { return false; } //if one of them null and the other is not it means that tree is not symmetric
        if (left->val != right->val) { return false; } //if values are not same, tree is not symmetric
   
        return (isMirror(left->left, right->right) && isMirror(left->right, right->left)); //recursive.
    
    }
};















