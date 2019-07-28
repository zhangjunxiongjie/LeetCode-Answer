/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// 未解决
bool isSymmetric(struct TreeNode* root){
    if (root == NULL)
    {
        return true;
    }
    
    struct TreeNode* cache_first[1000];
    int lenf = 0;

    struct TreeNode* cache_last[1000];
    int lenl = 0;
    
    bool sign = true;
    
    cache_first[lenf++] = root;
    
    while (true)
    {
        bool over_sign = true;

        if (sign)
        {
            lenl = 0;

            for(int i = 0; i < lenf; i++)
            {
                if (cache_first[i])
                {
                    cache_last[lenl++] = cache_first[i]->left;
                    cache_last[lenl++] = cache_first[i]->right;
                    over_sign = false;
                }
                else
                {
                    cache_last[lenl++] = NULL;
                    cache_last[lenl++] = NULL;
                }
                
            }

            for (int i = 0; i < lenl/2; i++)
            {
                
                if ((cache_last[i] == NULL && cache_last[lenl - i - 1]) || (cache_last[i] && cache_last[lenl - i - 1] == NULL) || (cache_last[lenl - i - 1] && cache_last[i] && cache_last[i]->val != cache_last[lenl - i - 1]->val))
                {
                    return false;
                }
                
            }
        
            sign = false;
        }
        else
        {
            lenf = 0;
            for(int i = 0; i < lenl; i++)
            {
                if(cache_first[i])
                {
                    cache_last[lenf++] = cache_first[i]->left;
                    cache_last[lenf++] = cache_first[i]->right;
                    over_sign = false;
                }
                else
                {
                    cache_last[lenf++] = NULL;
                    cache_last[lenf++] = NULL;
                }
            }

            for (int i = 0; i < lenf/2; i++)
            {
                if ((cache_first[i] == NULL && cache_first[lenf - i - 1]) || (cache_first[i] && cache_first[lenf - i - 1] == NULL) || (cache_first[lenf - i - 1] && cache_first[i] && cache_first[i]->val != cache_first[lenf - i - 1]->val))
                {
                    return false;
                }
                
            }
        
            sign = true;
        }
        
        if (over_sign)
        {
            return true;
        }
        
    }
    
}



