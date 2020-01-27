/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    void recursion(TreeNode* root, int buffer, int& result){
        buffer = buffer * 10 + root->val;
        if(root->right == nullptr && root->left == nullptr)
        {
            result += buffer;
            return ;
        }
        if (root->left != nullptr)
        {
            recursion(root->left, buffer, result);
        }
        if(root->right != nullptr)
        {
            recursion(root->right, buffer, result);
        }
        
    }
    // 可以使用循环加堆栈的方法实现。
    int sumNumbers(TreeNode* root) {
        int result = 0;
        if (root == nullptr)
        {
            return result;
        }
        else
        {
            recursion(root, 0, result);
        }
        return result;
    }
};
// @lc code=end

