/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
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
    TreeNode* recursion(string& S, int& strCounter, int nowDepth)
    {
        if (S.size() == strCounter)
        {
            return nullptr;
        }
        
        int begin = strCounter;
        while (strCounter < S.size() && S.at(strCounter) == '-')
        {
            strCounter++;
        }
        int depth = strCounter - begin;
        
        if (depth != nowDepth)
        {
            strCounter = begin;
            return nullptr;
        }
        
        begin = strCounter;
        while (strCounter < S.size() && '0' <= S.at(strCounter) && S.at(strCounter) <= '9')
        {
            strCounter++;
        }
        string number = S.substr(begin, strCounter - begin);

        TreeNode* root = new TreeNode;
        if (depth == nowDepth && nowDepth == 0)
        {
            root->val = atoi(number.c_str());
            
            root->left = recursion(S, strCounter, nowDepth + 1);
            if (root->left != nullptr)
            {
                root->right = recursion(S, strCounter, nowDepth + 1);
            }
            else
            {
                root->right = nullptr;
            }
            
        }
        else if(depth == nowDepth)
        {
            root->val = atoi(number.c_str());

            // 题目要求保证了如果没有左子树就一定没有右子树。
            root->left = recursion(S, strCounter, nowDepth + 1);
            if (root->left != nullptr)
            {
                root->right = recursion(S, strCounter, nowDepth + 1);
            }
            else
            {
                root->right = nullptr;
            }
            
        }

        return root;
    }
    TreeNode* recoverFromPreorder(string S) {

        int strCounter = 0;
        
        TreeNode* root = nullptr;
        root = recursion(S, strCounter, 0);

        return root;
    }
};
// @lc code=end

