/*
 * @lc app=leetcode.cn id=1752 lang=c
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
bool check(int* nums, int numsSize){

    bool resultFlag = true;
    int numsIndex = 0;

    while (resultFlag) {

        for (int j = (numsIndex + 1); j != numsIndex; ) {
            
            if (j >= numsSize) {

                j = 0;
            }

            if ((j - 1) < 0) {
                
                if (nums[j] < nums[numsSize - 1]) {
                
                    if (j < numsIndex) {

                        resultFlag = false;
                        break;                      
                    }
                    else {

                        numsIndex = j;
                        break;
                    }
                }                
            }
            else {

                if (nums[j] < nums[j - 1]) {

                    if (j < numsIndex) {

                        resultFlag = false;
                        break;
                    }
                    else {

                        numsIndex = j;
                        break;
                    }
                }              
            }

            j++;
            if (j >= numsSize) {

                j = 0;
            }

            if (j == numsIndex) {

                resultFlag = true;
                return resultFlag;
            }
        }
    }

    return resultFlag;
}

// @lc code=end

