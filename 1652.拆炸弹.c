/*
 * @lc app=leetcode.cn id=1652 lang=c
 *
 * [1652] 拆炸弹
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct StackNode {

    int pointerValue;

    struct StackNode *nextNode;
    struct StackNode *lastNode;
};

struct StackNode *stackHeadPointer = NULL;
struct StackNode *stackTailPointer = NULL;

void pushStack(int nodeValue, int *slidingWindowSum)
{
    if (stackHeadPointer != NULL) {

        stackTailPointer->nextNode = malloc(sizeof(struct StackNode));

        stackTailPointer->nextNode->lastNode = stackTailPointer;                
        
        stackTailPointer = stackTailPointer->nextNode;
        stackTailPointer->nextNode = NULL;
        stackTailPointer->pointerValue = nodeValue;
        
        (*slidingWindowSum) += nodeValue;
    }
    else {

        initStack(nodeValue, slidingWindowSum);            
    }
    
    return ;    
}

int popStack(int *slidingWindowSum)
{
    int resultPointer = 0;
    struct TreeNode *nextPointer = NULL;

    if (NULL != stackHeadPointer) {

        resultPointer = stackHeadPointer->pointerValue;

        nextPointer = stackHeadPointer->nextNode;
        free(stackHeadPointer);
        stackHeadPointer = nextPointer;

        if (stackHeadPointer != NULL) {
            stackHeadPointer->lastNode = NULL;
        }

        (*slidingWindowSum) -= resultPointer;
    }

    return resultPointer;
}

bool isEmptyStack(voi)
{
    if ((stackHeadPointer == NULL)) {
        
        return true;
    }

    return false;
}

void initStack(int nodeValue, int *slidingWindowSum)
{

    stackHeadPointer = NULL;
    stackTailPointer = NULL;

    stackTailPointer = malloc(sizeof(struct StackNode));
    stackHeadPointer = stackTailPointer;

    stackTailPointer->pointerValue = nodeValue;
    stackTailPointer->nextNode = NULL;
    stackTailPointer->lastNode = NULL;
    
    (*slidingWindowSum) += nodeValue;
    
    return ;
}



int* decrypt(int* code, int codeSize, int k, int* returnSize){
        
    int *resultVector = malloc(sizeof(int) * codeSize);
    memset(resultVector, 0, (sizeof(int) * codeSize));
    
    int slidingWindowSum = 0;
    
    stackHeadPointer = NULL;
    stackTailPointer = NULL;

    if (k == 0) {
        
        (*returnSize) = codeSize;
        return resultVector;
    }
    else if (k < 0) {

        for (int i = k; i <= -1; i++) {
                        
            pushStack(code[codeSize + i], &slidingWindowSum);            
        }

        for (int i = 0; i < codeSize; i++) {

            resultVector[i] = slidingWindowSum;
            popStack(&slidingWindowSum);
            pushStack(code[i], &slidingWindowSum);
        }
    }
    else if (k > 0) {


        for (int i = 0; i <= k; i++) {
                        
            pushStack(code[i], &slidingWindowSum);
        }

        for (int i = 0; i < codeSize; i++) {
            
            popStack(&slidingWindowSum);                        

            resultVector[i] = slidingWindowSum;                    
            
            pushStack(code[(k + i + 1) % codeSize], &slidingWindowSum);
        }
    }
    
    (*returnSize) = codeSize;
    return resultVector;
}

// @lc code=end

