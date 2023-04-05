/*
 * @lc app=leetcode.cn id=1636 lang=c
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize){

    char assistantCounter[201];
    
    memset(assistantCounter, 0, (sizeof (char) * 201));
    
    for (int i = 0; (i < numsSize); i++) {

        assistantCounter[nums[i] + 100]++;
    }

    /*
    for (int i = 0; i < numsSize; i++) {
        
        printf ("%d, ", assistantCounter[nums[i] + 100]);
    }
    */
    
    for (int i = 0; i < numsSize; i++) {
        
        int targetIndex = i;
        
        for (int j = (targetIndex + 1); j < numsSize; j++) {

            if (assistantCounter[nums[targetIndex] + 100] > assistantCounter[nums[j] + 100]) {

                targetIndex = j;
            }
            else if ((assistantCounter[nums[targetIndex] + 100] == assistantCounter[nums[j] + 100]) &&
                (nums[targetIndex] < nums[j])
            ) {

                targetIndex = j;
            }
        }

        if (targetIndex != i) {

            nums[targetIndex] ^= nums[i];
            nums[i] ^= nums[targetIndex];
            nums[targetIndex] ^= nums[i];
        }
    }

    (*returnSize) = numsSize;

    return nums;
}

// @lc code=end

