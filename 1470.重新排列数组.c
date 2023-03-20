/*
 * @lc app=leetcode.cn id=1470 lang=c
 *
 * [1470] 重新排列数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    int *resultVector = malloc(sizeof(int) * numsSize);

    for (unsigned short i = 0; i < n; i++) {
        
        *(resultVector + (i * 2)) = nums[i];
        *(resultVector + (i * 2) + 1) = nums[i + n];
    }
    
    *returnSize = numsSize;
    return resultVector;
}

// @lc code=end

