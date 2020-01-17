/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
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
                // 只有当左右指针不为 null 时才加入队列。
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

