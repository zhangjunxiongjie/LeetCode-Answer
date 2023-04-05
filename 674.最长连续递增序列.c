/*
 * @lc app=leetcode.cn id=674 lang=c
 *
 * [674] 最长连续递增序列
 */

// @lc code=start


int findLengthOfLCIS(int* nums, int numsSize){

    int resultCounter = 0;

    for (int i = 0; i < numsSize; i++) {
        
        int j = i;
        int z = (i + 1);
        while ((z < numsSize) && (nums[j] < nums[z])) {
            
            j++;
            z++;
        }

        if ((z - i) > resultCounter) {

            resultCounter = z - i;
        }
    }

    return resultCounter;
}

// @lc code=end

