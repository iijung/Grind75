// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;
        if (isSubtree(root->left, subRoot))
            return true;
        if (isSubtree(root->right, subRoot))
            return true;
        return false;

    }
private:
    bool isIdentical(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;
        if (s->val != t->val)
            return false;
        if (!isIdentical(s->left, t->left))
            return false;
        if (!isIdentical(s->right, t->right))
            return false;
         return true;
    }
};
