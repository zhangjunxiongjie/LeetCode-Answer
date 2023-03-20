/*
 * @lc app=leetcode.cn id=896 lang=c
 *
 * [896] 单调数列
 */

// @lc code=start


bool isMonotonic(int* nums, int numsSize){

    bool middleFlag = false;
    bool middleFlag1 = false;

    for (int i = 0; i < (numsSize - 1); i++) {

        if (nums[i] > nums[i + 1]) {

            middleFlag = true;
        }

        if (nums[i] < nums[i + 1]) {

            middleFlag1 = true;            
        }

        if (middleFlag && middleFlag1) {

            return false;
        }
    }
    
    return true;
    
    /*
    if (middleFlag && (!middleFlag1)) {

        return true;
    }
    else if ((!middleFlag) && middleFlag1) {

        return true;
    }
    else if ((!middleFlag) && (!middleFlag1)) {

        return true;
    }
    else {

        return false;
    }
    */

    /*
    if (nums[0] < nums[numsSize - 1]) {

        // 增
        for (int i = 0; i < (numsSize - 1); i++) {

            if (nums[i] > nums[i + 1]) {

                return false;
            }
        }

        return true;
    }
    else if (nums[0] > nums[numsSize - 1]) {
        
        // 减
        for (int i = 0; i < (numsSize - 1); i++) {

            if (nums[i] < nums[i+1]) {

                return false;
            }
        }

        return true;
    }
    else {

        return true;
    }
    */
}


// @lc code=end

