/*
 * @lc app=leetcode.cn id=1748 lang=c
 *
 * [1748] 唯一元素的和
 */

// @lc code=start


int sumOfUnique(int* nums, int numsSize){
    
    unsigned char cacheCounter[101];
    int resultSum = 0;

    for (int i = 0; i < 101; i++) {
        
        cacheCounter[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {

        cacheCounter[nums[i]]++;
    }

    for (int i = 0; i < 101; i++) {

        if (cacheCounter[i] == 1) {

            resultSum += i;
        }
    }


    return resultSum;
}

// @lc code=end

