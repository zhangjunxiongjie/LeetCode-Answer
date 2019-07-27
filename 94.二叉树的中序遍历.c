/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



// 循环迭代的求解方法
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{



}


/* 
// 第一版，递归的求解方法。 
void assistant(struct TreeNode* root, int* middle, int* flag)
{
    if (root->left)
        assistant(root->left, middle, flag);

    if(root)
        middle[(*flag)++] = root->val;

    if(root->right)
        assistant(root->right, middle, flag);
    
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }

    int* result = malloc(sizeof(int) * 1000);

    assistant(root, result, returnSize);

    return result;
}
*/


