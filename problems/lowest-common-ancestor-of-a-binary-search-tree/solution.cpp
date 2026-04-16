// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        if (p->val > q->val) // swap p and q
            return lowestCommonAncestor(root, q, p);
        if (root->val > q->val) // val > max_pq
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val) // val < min_pq
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
