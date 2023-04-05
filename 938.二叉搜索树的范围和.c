/*
 * @lc app=leetcode.cn id=938 lang=c
 *
 * [938] 二叉搜索树的范围和
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

struct StackNode {

    struct TreeNode *pointerValue;

    struct StackNode *nextNode;
    struct StackNode *lastNode;
};

struct StackNode *stackPointer = NULL;

void pushStack(struct TreeNode *root)
{
    if (root != NULL) {
        
        // printf("%d, ", root->val);

        if (stackPointer != NULL) {

            stackPointer->nextNode = malloc(sizeof(struct StackNode));

            stackPointer->nextNode->lastNode = stackPointer;
            stackPointer = stackPointer->nextNode;
            stackPointer->pointerValue = root;
            stackPointer->nextNode = NULL;
        }
        else {

            initStack(root);
        }
        
    }
    
    return ;    
}

struct TreeNode *popStack(void)
{
    struct TreeNode *resultPointer = NULL;
    struct TreeNode *lastPointer = NULL;

    if (NULL != stackPointer) {

        resultPointer = stackPointer->pointerValue;
        // printf("%d, ", stackPointer->pointerValue->val);

        lastPointer = stackPointer->lastNode;
        free(stackPointer);
        stackPointer = lastPointer;
    }

    return resultPointer;
}

bool isEmptyStack(voi)
{
    if (stackPointer == NULL) {
        
        return true;
        // printf("%d, ", stackPointer->pointerValue->val);
    }

    return false;
}

void initStack(struct TreeNode *root)
{

    stackPointer = NULL;

    if (root != NULL) {

        stackPointer = malloc(sizeof(struct StackNode));

        stackPointer->pointerValue = root;
        stackPointer->nextNode = NULL;
        stackPointer->lastNode = NULL;

        // printf("%d, ", stackPointer->pointerValue->val);
    }
    
    return ;
}

int rangeSumBST(struct TreeNode* root, int low, int high){
    
    int resultSum = 0;

    struct TreeNode *treePointer = root;

    while (treePointer != NULL) {

        if (treePointer->left != NULL) {
            
            pushStack(treePointer);
            
            struct TreeNode *treePointerTemp = treePointer->left;
            treePointer->left = NULL;

            treePointer = treePointerTemp;

        }
        else {
            
            if ((low <= treePointer->val) && (treePointer->val <= high)) {

                resultSum += treePointer->val;
            }            
            
            // printf ("%d, ", treePointer->val);

            if (high < treePointer->val) {

                treePointer = NULL;
            }
            else {

                if (treePointer->right != NULL) {
                                        
                    struct TreeNode *treePointerTemp = treePointer->right;
                    treePointer->right = NULL;
                    treePointer = treePointerTemp;
                }
                else {

                    treePointer = popStack();
                }                
            }
        }
    }

    while (!isEmptyStack()) {
        
        popStack();
    }

    return resultSum;
}

// @lc code=end

