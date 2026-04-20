// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        max_diameter = 0;
        get_length(root);
        return max_diameter;
    }
private:
    int max_diameter = 0;

    int get_length(TreeNode* node) {
        if (node == nullptr)
            return 0;
        const int left = get_length(node->left);
        const int right = get_length(node->right);
        max_diameter = max(max_diameter, left + right);
        return 1 + max(left, right);
    }
};
