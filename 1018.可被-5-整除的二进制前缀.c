/*
 * @lc app=leetcode.cn id=1018 lang=c
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize){
    
    bool *resultVector = malloc(sizeof(bool) *numsSize);
    bool *resultVectorPointer = resultVector;

    unsigned int targetValue = 0;

    for (int *numsPointer = nums; (numsPointer < (nums + numsSize)); numsPointer++) {

        targetValue <<= 1;
        if ((*numsPointer) == 1) {

            targetValue |= 1;
        }
        targetValue %= 100;

        if ((targetValue % 5) == 0
        ) {      

            (*resultVectorPointer) = true;
        }
        else {

            (*resultVectorPointer) = false;
        }

        resultVectorPointer++;
    }
    
    
    (*returnSize) = numsSize; 

    return resultVector;
}
// @lc code=end

