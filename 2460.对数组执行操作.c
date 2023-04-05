/*
 * @lc app=leetcode.cn id=2460 lang=c
 *
 * [2460] 对数组执行操作
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize){

    for (int i = 0; i < numsSize; i++) {

        if (((i + 1) < numsSize) && (nums[i] == nums[i + 1])) {

            nums[i] = nums[i] * 2;
            nums[i + 1] = 0;
        }

        // printf ("%d, ", nums[i]);
    }

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] == 0) {

            int j = (i + 1);
            for (; j < numsSize; j++) {

                if (nums[j] != 0) {

                    int middle = nums[i];
                    nums[i] = nums[j];
                    nums[j] = middle;
                    break;
                }
            }

            if (j == numsSize) {
                
                break;
            }
        }
    }

    (*returnSize) = numsSize;
    return nums;
}

// @lc code=end

