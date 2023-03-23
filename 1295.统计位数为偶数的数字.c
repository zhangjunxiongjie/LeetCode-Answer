/*
 * @lc app=leetcode.cn id=1295 lang=c
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start


int findNumbers(int* nums, int numsSize){
    
    int resultCounter = 0;

    for (int i = 0; i < numsSize; i++) {

        int counter = 0;
        while (nums[i] != 0) {

            nums[i] /= 10;
            counter++;
        }

        if ((counter % 2) == 0) {
            
            resultCounter++;
        }
    }

    return resultCounter;
}

// @lc code=end

