/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    // 递归实现，时间复杂度和空间复杂度较高。可以改为迭代。
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder){
        if (preorder.size() == 0)
        {
            return nullptr;
        }
        else
        {
            TreeNode* root = new TreeNode;
            root->val = preorder.at(0);
            
            int flag = 0;
            for (; flag < inorder.size(); flag++)
            {
                if (inorder.at(flag) == preorder.at(0))
                {
                    break;
                }
            }
            
            vector<int> inorderleft;
            vector<int> inorderright;
            for (int i = 0; i < inorder.size(); i++)
            {
                if (i < flag)
                {
                    inorderleft.push_back(inorder.at(i));
                }
                else if(i > flag)
                {
                    inorderright.push_back(inorder.at(i));
                }
            }
            
            vector<int> preorderleft;
            vector<int> preorderright;
            for (int i = 1; i < preorder.size(); i++)
            {
                if (i <= inorderleft.size())
                {
                    preorderleft.push_back(preorder.at(i));
                }
                else
                {
                    preorderright.push_back(preorder.at(i));
                }
            }
            
            root->left = recursion(preorderleft, inorderleft);
            root->right = recursion(preorderright, inorderright);
            
            return root;
        }
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root = recursion(preorder, inorder);
        
        return root;
    }
};
// @lc code=end

