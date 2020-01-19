/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>& result = *new vector<vector<int>>;

        stack<TreeNode*> heap; // 堆栈
        TreeNode* move = root; // 根节点、
        TreeNode* lastnode = nullptr; // 上一个节点。
        int num = 0; // 所求和。
        vector<int> buffer;
        while (!heap.empty() || move != nullptr)
        {
            // 队列实现二叉树的后序遍历。
            while (move)
            {
                heap.push(move);
                
                num += move->val;
                buffer.push_back(move->val);

                move = move->left;
            }
            
            move = heap.top();
            if (move->right == nullptr || move->right == lastnode)
            {
                if (move->right == nullptr && move->left == nullptr && num == sum)
                {
                    result.push_back(buffer);
                }
                num -= move->val;
                buffer.pop_back();

                heap.pop();
                lastnode = move;
                move = nullptr;
            }            
            else
            {
                lastnode = move;
                move = move->right;    
            }
        }
        return result;
    }
};
// @lc code=end

