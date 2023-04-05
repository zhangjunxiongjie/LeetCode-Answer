/*
 * @lc app=leetcode.cn id=1413 lang=c
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start


int minStartValue(int* nums, int numsSize){
    int minimumValue = 100;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {

        sum += nums[i];
        if (sum < minimumValue) {
            minimumValue = sum;
        }
    }

    if (minimumValue < 1) {

        return (1 - minimumValue);
    }
    else {

        return 1;
    }
}

// @lc code=end

