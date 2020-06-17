/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
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
    int recursion(TreeNode* root, int& result)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftTree = 0;
        int rightTree = 0;
        if(root->left != nullptr)
        {
            leftTree = recursion(root->left, result) + 1;
        }
        if(root->right != nullptr)
        {
            rightTree = recursion(root->right, result) + 1;
        }

        result = max(result, (leftTree + rightTree));
        return max(leftTree, rightTree);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;

        recursion(root, result);

        return result;
    }
};
// @lc code=end

