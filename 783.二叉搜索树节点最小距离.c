/*
 * @lc app=leetcode.cn id=783 lang=c
 *
 * [783] 二叉搜索树节点最小距离
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

int minDiffInBST(struct TreeNode* root){
    int firstMinimumValue = 100000;
    int lastNodeValue = 100001;

    struct TreeNode *treePointer;

    initStack(root);

    while (!isEmptyStack()) {

        treePointer = popStack();
        
        // printf("%d, ", treePointer->val);

        if (treePointer->left != NULL) {
            
            pushStack(treePointer);
            pushStack(treePointer->left);

            treePointer->left = NULL;
        }
        else {

            // 处理中间
            // printf("%d, ", treePointer->val);

            if (lastNodeValue == 100001) {
                
                lastNodeValue = treePointer->val;
            }
            else {                

                if (abs(lastNodeValue - treePointer->val) < firstMinimumValue) {

                    firstMinimumValue = abs(lastNodeValue - treePointer->val);
                }

                lastNodeValue = treePointer->val;
            }

            pushStack(treePointer->right);
        }
        

        /*
        if ((treePointer->left != NULL) && (abs(treePointer->left->val - treePointer->val) < firstMinimumValue)) {
            
            firstMinimumValue = abs(treePointer->left->val - treePointer->val);
        }
        
        if ((treePointer->right != NULL) && (abs(treePointer->right->val - treePointer->val) < firstMinimumValue)) {
            
            firstMinimumValue = abs(treePointer->right->val - treePointer->val);
        }
        */
    }

    return firstMinimumValue;
}



// @lc code=end

