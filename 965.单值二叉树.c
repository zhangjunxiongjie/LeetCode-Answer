/*
 * @lc app=leetcode.cn id=965 lang=c
 *
 * [965] 单值二叉树
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


bool isUnivalTree(struct TreeNode* root){

    bool resultFlag = false;

    struct TreeNode *treePointer = root;

    while (treePointer != NULL) {

        if (treePointer->left != NULL) {
            
            pushStack(treePointer);
            
            struct TreeNode *treePointerTemp = treePointer->left;
            treePointer->left = NULL;

            treePointer = treePointerTemp;

        }
        else {
            
            // printf ("%d, ", treePointer->val);

            if (treePointer->val != root->val) {

                resultFlag = false;
                break;
            }            

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

    if (isEmptyStack()) {

        if ((treePointer != NULL)) {

            if ((treePointer->val == root->val)) {
                
                resultFlag = true;
            }
        }
        else {

            resultFlag = true;
        }
        
    }
    else {

        while (!isEmptyStack()) {
        
            popStack();
        }
    }

    return resultFlag;

}

// @lc code=end

