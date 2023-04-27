/*
 * @lc app=leetcode.cn id=1920 lang=c
 *
 * [1920] 基于排列构建数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
    
    for (int i = 0; i < numsSize; i++) {
        
        // printf ("%d, %d\n", nums[i], nums[nums[i]]);

        nums[i] |= ((nums[nums[i]] & 0x0000ffff) << 16);
    }

    for (int i = 0; i < numsSize; i++) {

        nums[i] >>= 16;
    }

    (*returnSize) = numsSize;

    return nums;

    
    /*
    int *resultVessel = (int *)malloc(sizeof(int) * numsSize);
    
    (*returnSize) = numsSize;

    for (int i = 0; i < numsSize; i++) {

        resultVessel[i] = nums[nums[i]];
    }

    return resultVessel;
    */
}

// @lc code=end

