/*
 * @lc app=leetcode.cn id=2455 lang=c
 *
 * [2455] 可被三整除的偶数的平均值
 */

// @lc code=start
int averageValue(int* nums, int numsSize){

    int numsSum = 0;
    int numsCounter = 0;

    for (int i = 0; i < numsSize; i++) {

        if (((nums[i] % 2) == 0) && ((nums[i] % 3) == 0)) {

            numsSum += nums[i];
            numsCounter++;
        }
    }

    if (numsCounter) {

        return (int)(numsSum / numsCounter);
    }
    else {

        return 0;
    }
}

// @lc code=end

