/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> list;
        vector<int>& result = *new vector<int>;
        
        TreeNode* p = root;
        int count = 0, lastcount = 0;
        while (p != nullptr)
        {
            if (p->left)
            {
                list.push(p->left);
                count++;  // 记录每一层的个数。
            }
            if(p->right)
            {
                list.push(p->right);
                count++;
            }

            if (lastcount == 0) // 取完一层，保存最右边的数值。
            {
                result.push_back(p->val);
                lastcount = count;
                count = 0;
            }
            
            if (list.empty()) // 为空时退出循环。
            {
                break;
            }
            
            p = list.front();
            list.pop();
            lastcount--; // 
        }
        
        return result;
    }
};
// @lc code=end

