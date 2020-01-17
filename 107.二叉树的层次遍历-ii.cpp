/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>& result = *new vector<vector<int>>;

        queue<TreeNode*> que; // 队列。
        if (root)
        {
            que.push(root);
        }
        else
        {
            return result;
        }
        
        int sum = que.size(); // 记录每一层的指针个数以便从队列取出。 
        while (sum != 0)
        {
            vector<int> buffer;
            for (int i = 0; i < sum; i++)
            {
                // 不用判断 que.front() 为 null 因为加入队列时就限制了。
                buffer.push_back(que.front()->val);
                
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
            result.push_back(buffer);
        }
        
        // 先顺序层次遍历再按层交换
        for (int i = 0; i < result.size() / 2; i++)
        {
            swap(result.at(i), result.at(result.size() - i - 1));
        }

        return result;
    }
};
// @lc code=end

