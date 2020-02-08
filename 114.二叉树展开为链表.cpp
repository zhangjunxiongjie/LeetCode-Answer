/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    // 有待优化。时间复杂度空间复杂度均较高。
    void flatten(TreeNode* root) {
        stack<TreeNode*> heap;
        TreeNode* move = root;

        while (move)
        {
            if (move->left)
            {
                heap.push(move->right);
                move->right = move->left;
                move->left = nullptr;
            }

            if (move->right)
            {
                move = move->right;
            }
            else if(!heap.empty())
            {
                move->right = heap.top();
                heap.pop();
            }
            else
            {
                move = move->right; 
            }
            
        }
    }
};
// @lc code=end

