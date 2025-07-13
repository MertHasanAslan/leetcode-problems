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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) { return nullptr; }
        if(key < root->val) { root->left = deleteNode( root->left, key); }
        else if(key > root->val) { root->right = deleteNode( root->right, key); }

        else{
            // no child
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // single child
            else if((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr)){
                TreeNode* dummy = root;
                root = (root->left != nullptr) ? root->left : root->right;
                delete dummy;
            }
            // two child
            else{
                TreeNode* r_least = root->right;
                while(r_least->left != nullptr){ r_least = r_least->left; }
                root->val = r_least->val;
                root->right = deleteNode(root->right, r_least->val);
            }
        }
        return root;
    }
};