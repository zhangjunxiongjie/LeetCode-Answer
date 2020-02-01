/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // 二叉树的后序遍历的迭代实现需要动脑筋。
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>& result = *new vector<int>;
        
        TreeNode* move = root;  // 移动指针。
        TreeNode* lastnode = nullptr; // 上一个节点。
        stack<TreeNode*> heap; // 堆栈。
        while (!heap.empty() || move != nullptr){
            while (move){
                heap.push(move);
                move = move->left;
            }
            move = heap.top();
            if (move->right == nullptr || move->right == lastnode)
            {
                result.push_back(move->val);
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

