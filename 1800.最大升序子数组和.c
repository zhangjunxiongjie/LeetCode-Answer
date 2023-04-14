/*
 * @lc app=leetcode.cn id=1800 lang=c
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start


int maxAscendingSum(int* nums, int numsSize){
    
    int maxSum = 0;
    int maxSumTemp = 0;

    for (int *numsPointer = nums; numsPointer < (nums + numsSize); numsPointer++) {

        if (numsPointer == nums) {

            maxSumTemp = (*numsPointer);
        }
        else {

            if ((*numsPointer) > (*(numsPointer - 1))) {

                maxSumTemp += (*numsPointer);
            }
            else {

                maxSumTemp = (*numsPointer);
            }
        }

        if (maxSumTemp > maxSum) {

            maxSum = maxSumTemp;
        }
    }

    return maxSum;
}

// @lc code=end

