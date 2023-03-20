/*
 * @lc app=leetcode.cn id=1929 lang=c
 *
 * [1929] 数组串联
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    
    int *resultVector = malloc((sizeof(int) * numsSize * 2));
    
    (*returnSize) = (int)(numsSize * 2);

    // for (int index = 0, index1 = numsSize; index < numsSize; index++, index1++) {

    //     resultVector[index] = (nums[index]);
    //     resultVector[index1] = (nums[index]);        
    // }

    for (int index = 0; index < numsSize; index++) {

        *(resultVector + index) = (nums[index]);        
        *(resultVector + index + numsSize) = (nums[index]);
    }

    return resultVector;
}
// @lc code=end

