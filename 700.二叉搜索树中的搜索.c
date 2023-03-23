/*
 * @lc app=leetcode.cn id=700 lang=c
 *
 * [700] 二叉搜索树中的搜索
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


struct TreeNode* searchBST(struct TreeNode* root, int val){
    
    struct TreeNode *pointer = root;

    while (pointer != NULL) {

        if (val > pointer->val) {

            pointer = pointer->right;
        }
        else if (val < pointer->val) {

            pointer = pointer->left;
        }
        else {
            break;
        }
    }

    return pointer;
}


// @lc code=end

