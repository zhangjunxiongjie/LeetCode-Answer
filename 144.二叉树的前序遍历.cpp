/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // 堆栈，迭代实现二叉树前序遍历。
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>& result = *new vector<int>;
        
        TreeNode* move = root;
        stack<TreeNode*> heap; // 堆栈。
        while (!heap.empty() || move){
            while (move){
                heap.push(move);
                result.push_back(move->val); // 
                move = move->left;
            }
            move = heap.top()->right;
            heap.pop();
        }
        return result;
    }
};
// @lc code=end

