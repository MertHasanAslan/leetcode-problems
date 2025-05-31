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
class Solution { //faster
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        make_vector(root, v);
        return v[k-1];
    }
    void make_vector(TreeNode* node, vector<int>& v){
        if (node == nullptr){ return; }
        make_vector(node->left, v);
        v.push_back(node->val);
        make_vector(node->right, v);
    }
};

/* for better memory but not so fast
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        make_vector(root, v, k);
        return v[k-1];
    }
    void make_vector(TreeNode* node, vector<int>& v, const int &k){
        if (node == nullptr){ return; }
        make_vector(node->left, v, k);
        if (v.size() < k){
            v.push_back(node->val);
        }
        make_vector(node->right, v, k);
    }
};
 :) */