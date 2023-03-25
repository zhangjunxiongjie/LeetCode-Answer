/*
 * @lc app=leetcode.cn id=1848 lang=c
 *
 * [1848] 到目标元素的最小距离
 */

// @lc code=start


int getMinDistance(int* nums, int numsSize, int target, int start){

    int result = 1001;

    for (int i = 0; i < numsSize; i++) {

        if ((nums[i] == target) && (abs(i - start) < result)) {

            result = abs(i - start);
        }
    }

    return result;
}

// @lc code=end

