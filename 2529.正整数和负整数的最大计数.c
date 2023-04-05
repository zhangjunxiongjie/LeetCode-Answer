/*
 * @lc app=leetcode.cn id=2529 lang=c
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
int maximumCount(int* nums, int numsSize){
    
    int minusCounter = 0;
    int positiveCounter = 0;

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] < 0) {

            minusCounter++;
        }
        else if (nums[i] > 0) {

            positiveCounter++;
        }
    }

    return fmax(minusCounter, positiveCounter);
}

// @lc code=end

