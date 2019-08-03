/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 第二版，使用栈进行搜索,因为没有什么特殊要求也不需要做什么操作，
// 这里使用栈是一个不错的选择
int maxDepth(struct TreeNode* root){

    struct TreeNode* stack_first[1024];   
    struct TreeNode* stack_tail[1024]; 
    int headf = 0, headt = 0;
    stack_first[headf++] = root;

    bool flag = true;

    int count = 0;
    while (headt || headf)
    {
        bool sign = false;
        for (int i = 0; flag && i < headf && stack_first[i]; i++)
        {
            
            if(stack_first[i]->left)
                stack_tail[headt++] = stack_first[i]->left;
            if(stack_first[i]->right)
                stack_tail[headt++] = stack_first[i]->right;
            sign = true;
        
        }
        flag = false;
        headf = 0;

        if (sign)
        {
            count++;
            sign = false;
        }
        
        for (int i = 0; !flag && i < headt; i++)
        {
                
            if(stack_tail[i]->left)
                stack_first[headf++] = stack_tail[i]->left;
            if(stack_tail[i]->right)
                stack_first[headf++] = stack_tail[i]->right;
            sign = true;
            
        }
        flag = true;
        headt = 0;

        if (sign)
        {
            count++;
        }
        
    }
    
    return count;
}



/* // 第一版，递归搜索二叉树
int Max(int left, int right)
{
    if (left > right)
        return left;
    else
        return right;
    
}

int Along_tree(struct TreeNode* tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if(tree->left && tree->right)
    {
        return Max(Along_tree(tree->left), Along_tree(tree->right)) + 1; 
    }
    else if(tree->left)
    {
        return Along_tree(tree->left) + 1;
    }
    else if(tree->right)
    {
        return Along_tree(tree->right) + 1;
    }
    else
    {
        return 1;
    }
      
}



int maxDepth(struct TreeNode* root){

    return Along_tree(root);
}
*/


