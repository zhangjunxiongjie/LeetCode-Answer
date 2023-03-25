/*
 * @lc app=leetcode.cn id=1480 lang=c
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    
    int sum = 0;
    // int *numsVector = malloc(sizeof(int) * numsSize);
    int *p = nums;

    for (int i = 0; i < numsSize; i++) {

        sum += (*p);
        (*p) = sum;
        p++;
    }
    
    (*returnSize) = numsSize;

    return nums;
}


// @lc code=end

