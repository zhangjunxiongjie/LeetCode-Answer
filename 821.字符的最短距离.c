/*
 * @lc app=leetcode.cn id=821 lang=c
 *
 * [821] 字符的最短距离
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * s, char c, int* returnSize){

    int *resultVector = malloc(sizeof(int) * strlen(s));
    int *resultVectorPointer = resultVector;
    
    int cCharIndex = strlen(s);
    for (int i = 0; i < strlen(s); i++) {

        if (s[i] == c) {

            cCharIndex = i;
        }

        (*resultVectorPointer) = abs(i - cCharIndex);        
        resultVectorPointer++;
    }

    resultVectorPointer--;
    cCharIndex = 0;
    for (int i = (strlen(s) - 1); i >= 0; i--) {

        if (s[i] == c) {
            cCharIndex = i;
        }

        if (abs(cCharIndex - i) < (*resultVectorPointer)) {

            (*resultVectorPointer) = abs(cCharIndex - i);    
        }        
        resultVectorPointer--;
    }

    (*returnSize) = strlen(s);
    return resultVector;
}

// @lc code=end

