/*
 * @lc app=leetcode.cn id=1022 lang=c
 *
 * [1022] 从根到叶的二进制数之和
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
/*
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
*/



void recursion(struct TreeNode* root, int *resultSum, int currentValue)
{
    currentValue <<= 1;

    if (root->val) {

        currentValue |= 1;
    }

    if (root->left != NULL) {

        recursion(root->left, resultSum, currentValue);
    }

    if (root->right != NULL) {

        recursion(root->right, resultSum, currentValue);
    }

    if ((root->left == NULL) && (root->right == NULL)) {

        (*resultSum) += currentValue;
    }
}

int sumRootToLeaf(struct TreeNode* root){
    
    int resultSum = 0;
    int currentValue = 0;

    struct TreeNode *treePointer = root;

    recursion(root, (&resultSum), currentValue);

    return resultSum;
}

// @lc code=end

