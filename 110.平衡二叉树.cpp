/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

    // 使用递归的方法，在回溯时能更加快速的进行判断。
    int recursion(TreeNode* root, bool& result)
    {
        // 当得出非平衡树结论时即退出不再试探。
        if (result) 
        {
            if (root == nullptr)
            {
                return 0;
            }
            
            int leftdeep = recursion(root->left,result); 
            int rightdeep = recursion(root->right,result);

            int bad = leftdeep - rightdeep;
            if (bad < -1 || bad > 1)
            {
                result = false;
            }

            if (leftdeep > rightdeep)
            {
                return leftdeep + 1;
            }
            else
            {
                return rightdeep + 1;
            }
            
        }
        else
        {
            return 0;
        }
    }

    bool isBalanced(TreeNode* root) {
        bool result = true;
        
        recursion(root, result);

        return result;
    }
};
// @lc code=end

