/*
 * @lc app=leetcode.cn id=1512 lang=c
 *
 * [1512] 好数对的数目
 */

// @lc code=start


int numIdenticalPairs(int* nums, int numsSize){
    
    int resultCounter = 0;

    for (unsigned char i = 0; i < numsSize; i++) {

        for (unsigned char j = (i + 1); j < numsSize; j++) {

            if (nums[i] == nums[j]) {
                
                resultCounter++;
            }
        }
    }

    return resultCounter;
}

// @lc code=end

