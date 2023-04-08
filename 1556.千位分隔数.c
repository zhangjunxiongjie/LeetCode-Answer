/*
 * @lc app=leetcode.cn id=1556 lang=c
 *
 * [1556] 千位分隔数
 */

// @lc code=start

struct StackNode {

    char pointerValue;

    struct StackNode *nextNode;
    struct StackNode *lastNode;
};

struct StackNode *stackPointer = NULL;
int stackDeepCounter = 0;

void pushStack(char root)
{
    if (root != '\0') {
        
        // printf("%d, ", root->val);

        if (stackPointer != NULL) {

            stackPointer->nextNode = malloc(sizeof(struct StackNode));

            stackPointer->nextNode->lastNode = stackPointer;
            stackPointer = stackPointer->nextNode;
            stackPointer->pointerValue = root;
            stackPointer->nextNode = NULL;
            
            stackDeepCounter++;
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
    struct TreeNode *lastPointer = NULL;

    if (NULL != stackPointer) {

        resultPointer = stackPointer->pointerValue;
        // printf("%d, ", stackPointer->pointerValue->val);

        lastPointer = stackPointer->lastNode;
        free(stackPointer);
        stackPointer = lastPointer;

        stackDeepCounter--;
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

    if (root != '\0') {

        stackPointer = malloc(sizeof(struct StackNode));

        stackPointer->pointerValue = root;
        stackPointer->nextNode = NULL;
        stackPointer->lastNode = NULL;
        
        stackDeepCounter++;

        // printf("%d, ", stackPointer->pointerValue->val);
    }
    
    return ;
}


char * thousandSeparator(int n){

    // initStack();

    if (0 == n) {

        pushStack (n + '0');
    }
    else {

        while (n) {

            pushStack(((n % 10) + '0'));
            n /= 10;
        }
    }

    char *charVector = malloc(sizeof(char) * ((stackDeepCounter / 3) + stackDeepCounter + 1));

    char *charVectorPointer = charVector;
    int stackDeepCounterLast = stackDeepCounter;
    
    printf ("%d\n", (stackDeepCounter));

    while (stackDeepCounter % 3) {

        (*charVectorPointer) = popStack();
        charVectorPointer++;
    }
        
    while (!isEmptyStack()) {

        if ((stackDeepCounterLast != stackDeepCounter) && 
            ((stackDeepCounter % 3) == 0)
        ) {
                
            (*charVectorPointer) = '.';
            charVectorPointer++;
        }


        (*charVectorPointer) = popStack();
        charVectorPointer++;

    }

    (*charVectorPointer) = '\0';

    return charVector;
}

// @lc code=end

