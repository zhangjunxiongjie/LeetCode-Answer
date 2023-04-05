/*
 * @lc app=leetcode.cn id=1047 lang=c
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start

struct StackNode {

    char charValue;

    struct StackNode *nextNode;
    struct StackNode *lastNode;
};

struct StackNode *stackPointer = NULL;

void pushStack(char root)
{
    if (root != NULL) {
        
        // printf("%d, ", root->val);

        if (stackPointer != NULL) {

            stackPointer->nextNode = malloc(sizeof(struct StackNode));

            stackPointer->nextNode->lastNode = stackPointer;
            stackPointer = stackPointer->nextNode;
            stackPointer->charValue = root;
            stackPointer->nextNode = NULL;
        }
        else {

            initStack(root);
        }
        
    }
    
    return ;    
}

char popStack(void)
{
    char resultPointer = NULL;
    struct StackNode *lastPointer = NULL;

    if (NULL != stackPointer) {

        resultPointer = stackPointer->charValue;

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

void initStack(char root)
{

    stackPointer = NULL;

    if (root != NULL) {

        stackPointer = malloc(sizeof(struct StackNode));

        stackPointer->charValue = root;
        stackPointer->nextNode = NULL;
        stackPointer->lastNode = NULL;

        // printf("%d, ", stackPointer->pointerValue->val);
    }
    
    return ;
}


char * removeDuplicates(char * s){
    
    char *strPointer = (s + (strlen(s) - 1));

    while (strPointer >= s) {

        if (isEmptyStack()) {

            pushStack(*strPointer);
        }
        else {

            char middleChar = popStack();
            
            if (middleChar != (*strPointer)) {

                pushStack(middleChar);
                pushStack(*strPointer);
            }
        }

        strPointer--;
    }

    strPointer = s;
    while (!isEmptyStack()) {
        
        (*strPointer) = popStack();
        strPointer++;
    }
    (*strPointer) = '\0';
    /*
    strPointer--;
    for (char *strPointerLeft = s; strPointerLeft < strPointer; strPointer--, strPointerLeft++) {
        
        char middleChar = (*strPointer);
        (*strPointer) = (*strPointerLeft);
        (*strPointerLeft) = middleChar;
    }
    */
    return s;
}

// @lc code=end

