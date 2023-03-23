/*
 * @lc app=leetcode.cn id=1304 lang=c
 *
 * [1304] 和为零的 N 个不同整数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    
    int *resultVector = malloc(sizeof(int) * n);
    int resultVectorIndex = 0;
    int cacheIndex = 1;

    (*returnSize) = n;
    
    if ((n % 2) == 1) {

        resultVector[resultVectorIndex++] = 0;
        n--;
    }

    for (; n > 0; n -= 2) {

        resultVector[resultVectorIndex++] = cacheIndex;
        resultVector[resultVectorIndex++] = (-cacheIndex);
        
        cacheIndex++;
    }


    return resultVector;
}


// @lc code=end

