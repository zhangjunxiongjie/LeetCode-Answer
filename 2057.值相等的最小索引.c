/*
 * @lc app=leetcode.cn id=2057 lang=c
 *
 * [2057] 值相等的最小索引
 */

// @lc code=start


int smallestEqual(int* nums, int numsSize){

    for (int index = 0; index < numsSize; index++) {

        if ((index % 10) == nums[index]) {
            
            return index;
        }
    }

    return -1;
}

// @lc code=end

