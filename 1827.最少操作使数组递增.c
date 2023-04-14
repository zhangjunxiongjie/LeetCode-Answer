/*
 * @lc app=leetcode.cn id=1827 lang=c
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start


int minOperations(int* nums, int numsSize){

    int numsValueLast = 0;
    int resultSum = 0;

    for (int *numsPointer = nums; numsPointer < (nums + numsSize); numsPointer++) {

        if (numsValueLast >= (*numsPointer)) {

            resultSum += (numsValueLast + 1) - (*numsPointer);

            numsValueLast = (numsValueLast + 1);
        }
        else {

            numsValueLast = (*numsPointer);
        }        
    }   

    return resultSum;
}

// @lc code=end

