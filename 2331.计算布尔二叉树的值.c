/*
 * @lc app=leetcode.cn id=2331 lang=c
 *
 * [2331] 计算布尔二叉树的值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool recursion(struct TreeNode* root)
{
    bool resultBool;

    if (root == NULL) {

    }
    else {

        if ((root->left == NULL) && (root->right == NULL)) {

            if (root->val == 0) {

                resultBool = false;
            }
            else if (root->val == 1) {

                resultBool = true;
            }
        }
        else if (root->val == 2) {
            // 剪枝
            if (recursion(root->left)) {

                resultBool = true;
            }
            else if (recursion(root->right)) {

                resultBool = true;
            }
            else {

                resultBool = false;
            }
        }
        else if (root->val == 3) {
            // 剪枝
            if (!recursion(root->left)) {

                resultBool = false;
            }
            else if (!recursion(root->right)) {

                resultBool = false;
            }
            else {

                resultBool = true;
            }
        }
        
    }

    return resultBool;
}

bool evaluateTree(struct TreeNode* root){
    
    bool resultBool;

    resultBool = recursion(root);

    return resultBool;
}
// @lc code=end

