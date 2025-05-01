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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) { return nullptr; }

        return add_tree(0, nums.size()-1, nums);

    }

    TreeNode* add_tree(int start, int end, vector<int>& nums){
        if (start > end){return nullptr;}

        int mid = (start + end) / 2;    

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = add_tree(start, mid-1, nums);
        node->right = add_tree(mid+1, end, nums);

        return node;

    }
};