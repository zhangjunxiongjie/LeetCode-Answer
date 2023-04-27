/*
 * @lc app=leetcode.cn id=747 lang=c
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start


int dominantIndex(int* nums, int numsSize){

    if (numsSize == 1) {
        // 只有一个数字时
        return 0;
    }
    else {
        int maxNumber = 0;
        int maxNumberIndex = 0;

        int secondNumber = 0;

        for (int i = 0; i < numsSize; i++) {

            if (nums[i] > maxNumber) {
                
                secondNumber = maxNumber;

                maxNumber = nums[i];
                maxNumberIndex = i;
            }
            else if (secondNumber < nums[i]) {

                secondNumber = nums[i];
            }
        }

        if (maxNumber >= (secondNumber * 2)) {

            return maxNumberIndex;
        }
        else {

            return -1;
        }
    }
}

// @lc code=end

