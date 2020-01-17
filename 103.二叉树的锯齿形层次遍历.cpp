/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        bool flag = false;
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
            
            if (flag)
            {   
                // 不使用额外空间。
                for (int i = 0; i < buffer.size() / 2; i++)
                {
                    swap(buffer.at(i), buffer.at(buffer.size() - i - 1));
                }
                
                // 使用额外空间。
                /*
                stack<int> heap;
                for (int i = 0; i < buffer.size(); i++) // 入栈，
                {
                    heap.push(buffer.at(i));
                }
                buffer.clear();
                while (!heap.empty()) // 出栈。
                {
                    buffer.push_back(heap.top());
                    heap.pop();
                }
                */
            }
            flag = !flag; // 反向。

            result.push_back(buffer);
        }
        return result;
    }
};
// @lc code=end

