/*
 * @lc app=leetcode.cn id=2535 lang=c
 *
 * [2535] 数组元素和与数字和的绝对差
 */

// @lc code=start
int differenceOfSum(int* nums, int numsSize){
    
    int elementSum = 0;
    int digitSum = 0;

    for (int i = 0; i < numsSize; i++) {

        elementSum += nums[i];
        
        int middle = nums[i];
        while (middle) {

            digitSum += (middle % 10);
            middle /= 10;
        }
    }

    return abs(digitSum - elementSum);
}

// @lc code=end

