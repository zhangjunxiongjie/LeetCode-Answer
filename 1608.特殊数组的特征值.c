/*
 * @lc app=leetcode.cn id=1608 lang=c
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start


int specialArray(int* nums, int numsSize){

    int resultNumber = -1;

    for (int i = 0; i < numsSize; i++) {

        int targetIndex = i;
        for (int j = (targetIndex + 1); j < numsSize; j++) {


            if (nums[targetIndex] < nums[j]) {

                targetIndex = j;
            }
        }

        if (targetIndex != i) {

            nums[targetIndex] ^= nums[i];
            nums[i] ^= nums[targetIndex];
            nums[targetIndex] ^= nums[i];
        }
    }

    for (int i = (numsSize - 1); i >= 0; i--) {

        if ((i > nums[i]) && ((i - 1) >= 0) && (i <= nums[i - 1])) {

            resultNumber = i;
            break;
        }

        // printf ("%d, ", nums[i]);
    }

    if ((resultNumber == -1) && (nums[numsSize - 1] >= numsSize)) {
    
        resultNumber = numsSize;    
    }

    return resultNumber;
}

// @lc code=end

