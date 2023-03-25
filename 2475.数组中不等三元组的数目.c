/*
 * @lc app=leetcode.cn id=2475 lang=c
 *
 * [2475] 数组中不等三元组的数目
 */

// @lc code=start
int unequalTriplets(int* nums, int numsSize){
    
    int resultTarget = 0;

    for (int i = 0; i < numsSize; i++) {

        for (int j = i + 1; j < numsSize; j++) {

            for (int z = j + 1; z < numsSize; z++) {

                if ((nums[i] != nums[j]) && 
                    (nums[j] != nums[z]) && 
                    (nums[i] != nums[z])
                ) {
                    resultTarget++;
                }
            }
        }
    }

    return resultTarget;
}


// @lc code=end

