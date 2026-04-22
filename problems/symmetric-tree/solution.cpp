// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return dfs(root->left, root->right);
    }
private:
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        if (dfs(left->left, right->right) == false)
            return false;
        if (dfs(left->right, right->left) == false)
            return false;
        return true;
    }
    bool bfs(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            const TreeNode* const left = q.front();
            q.pop();
            const TreeNode* const right = q.front();
            q.pop();
            if (left == nullptr && right == nullptr)
                continue;
            if (left == nullptr || right == nullptr)
                return false;
            if (left->val != right->val)
                return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
