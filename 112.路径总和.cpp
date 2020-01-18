/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

    bool hasPathSum(TreeNode* root, int sum) {
        bool result = false;

        stack<TreeNode*> heap; // 堆栈
        TreeNode* move = root; // 根节点、
        TreeNode* lastnode = nullptr; // 上一个节点。
        int num = 0; // 所求和。
        while ((!heap.empty() || move != nullptr) && result == false)
        {
            // 队列实现二叉树的后序遍历。
            while (move)
            {
                heap.push(move);
                num += move->val;
                move = move->left;
            }
            
            move = heap.top();
            if (move->right == nullptr || move->right == lastnode)
            {
                if (move->right == nullptr && move->left == nullptr && num == sum)
                {
                    result = true;
                }
                num -= move->val;
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

