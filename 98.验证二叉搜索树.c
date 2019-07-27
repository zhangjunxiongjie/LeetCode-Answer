/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



// 第一版，递归搜索的方法，但是这种方法有个缺点就是在判断出为false时可能会继续搜索。（还可以使用迭代的方法实现）
// 另要注意的是，这个题并不是判断是否是“二叉搜索树”，这里“二叉搜索树”定义与一般的二叉搜索树不同。
// 它要求整个左树都小于当前值，整个右树都大于当前值；这个定义并不是数据额结构中一般意义上的二叉搜索树。
bool assistant(struct TreeNode* root, long int min_num, long int max_num)
{

    if (root->val > min_num && root->val < max_num)
    {
        if (root->left && root->right)
        {
            if (root->left->val < root->val && root->val < root->right->val)
                return (assistant(root->left, min_num, root->val) && assistant(root->right, root->val, max_num));            

            else
                return false;

        }
        else if(root->left)
        {
            if (root->left->val < root->val)
                return assistant(root->left, min_num, root->val);

            else
                return false;

        }
        else if(root->right)
        {
            if (root->right->val > root->val)
                return assistant(root->right, root->val, max_num);

            else
                return false;

        }
        else
        {
            return true;
        }
        
    }
    else
        return false;   
    
}

bool isValidBST(struct TreeNode* root){
    
    if (root == NULL)
        return true;
    
    return assistant(root, -2147483649, 2147483649);
}



