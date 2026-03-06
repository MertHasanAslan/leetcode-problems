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
    unordered_map<int, vector<int>> m;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int level = 0;
        levelOrderHelper(root, level);
        for (int i = 0; i < m.size(); i++){
            result.push_back(m[i]);
        }
        return result;
    }

    void levelOrderHelper(TreeNode* node, int level){
        if (!node) { return; }
        m[level].push_back(node->val);        
        levelOrderHelper(node->left, level+1);
        levelOrderHelper(node->right, level+1);
    }
};
