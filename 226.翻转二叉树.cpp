/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    // 内存消耗较大。
    // 这个题翻转的实质就是每个子树进行翻转
    TreeNode* invertTree(TreeNode* root) {
        
        queue<TreeNode*> que; // 队列。
        if (root)
        {
            que.push(root);
        }
        else
        {
            return root;
        }
        
        int sum = que.size(); // 记录每一层的指针个数以便从队列取出。 
        while (sum != 0)
        {
            for (int i = 0; i < sum; i++)
            {
                // 翻转。
                TreeNode* middle = que.front()->left;
                que.front()->left = que.front()->right;
                que.front()->right = middle;

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
        return root;
    }
};
// @lc code=end

