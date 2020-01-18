/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        int result = 0;

        queue<TreeNode*> que; // 队列。
        if (root)
        {
            que.push(root);
        }
        else
        {
            return result;
        }
        
        int sum = que.size(); 
        while (sum != 0)
        {
            result++;
            for (int i = 0; i < sum; i++)
            {
                if (que.front()->left == nullptr && que.front()->right == nullptr)
                {
                    return result;
                }

                if (que.front()->left)
                {
                    que.push(que.front()->left);
                }
                if (que.front()->right)
                {
                    que.push(que.front()->right);
                }
                que.pop();
            } 
            sum = que.size();
        }
        return result;
    }
};
// @lc code=end

