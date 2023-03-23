/*
 * @lc app=leetcode.cn id=1437 lang=c
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 */

// @lc code=start


bool kLengthApart(int* nums, int numsSize, int k){
    
    int frontIndex = 0;
    int behindIndex = 0;
    
    while ((frontIndex < numsSize) && (nums[frontIndex] != 1)) {
            
        frontIndex++;
    }

    behindIndex = frontIndex++;
    
    while ((frontIndex < numsSize) && (nums[frontIndex] != 1)) {
            
        frontIndex++;
    }

    // printf ("%d, %d\n", nums[behindIndex], nums[frontIndex]);

    while (true) {

        if ((frontIndex < numsSize)           
            ) {

            if ((frontIndex - behindIndex - 1) < k) {
                
                return false;
            }

            // printf ("%d, %d\n", behindIndex, frontIndex);
        }
        else {
            break;
        }
        behindIndex = frontIndex++;

        while ((frontIndex < numsSize) && (nums[frontIndex] != 1)) {
            
            frontIndex++;
        }

    }

    return true;
}

// @lc code=end

