/*
 * @lc app=leetcode.cn id=3427 lang=c
 *
 * [3427] 变长子数组求和
 */

// @lc code=start
int subarraySum(int* nums, int numsSize) {
    
    int result = 0;

    for (int i = 0; i < numsSize; i++) {

        for (int j = fmax(0, (i - nums[i])); j <= i; j++) {

            result += nums[j];
        }
    }

    return result;
}

// @lc code=end

