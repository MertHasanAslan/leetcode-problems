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
    vector<int> result;
    int max = -1;
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return result;
    }


    void helper(TreeNode* node, int rl){
        if (!node) { return; }
        if (rl > max){
            result.push_back(node->val);
            max = rl;
        }
        
        
        helper(node->right, rl+1);
        helper(node->left, rl+1);
    }
};
