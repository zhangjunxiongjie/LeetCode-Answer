/*
 * @lc app=leetcode.cn id=2089 lang=c
 *
 * [2089] 找出数组排序后的目标下标
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    int *resultVector = NULL;    

    int LeftIndex = 0;
    int RightIndex = 0;

    bool flag = false;
    bool flag1 = false;

    (*returnSize) = 0;

    for (int i = 0; i < numsSize; i++) {
        
        int switchIndex = (i);
        for (int j = (i + 1); j < numsSize; j++) {

            if (nums[switchIndex] > nums[j]) {
                
                switchIndex = j;
            }
        }

        if (switchIndex != i) {
            int middle = nums[switchIndex];
            nums[switchIndex] = nums[i];
            nums[i] = middle;
        }

        if ((!flag) && (nums[i] == target)) {

            flag = true;
            LeftIndex = i;
        }

        if (flag && (!flag1)) {

            if ((nums[i] != target)) {

                flag1 = true;

                RightIndex = i;
            }
            
            if ((i == (numsSize - 1)) && (nums[i] == target)) {
                flag1 = true;

                RightIndex = numsSize;
            }
        }

        // printf ("%d,", nums[i]);
    }
    
    // printf ("\n%d, %d", LeftIndex, RightIndex);    

    if (LeftIndex < RightIndex) {

        resultVector = malloc(sizeof(int) * (RightIndex - LeftIndex));
        (*returnSize) = (RightIndex - LeftIndex);
    }

    for (int i = 0; (LeftIndex + i) < RightIndex; i++) {

        resultVector[i] = (LeftIndex + i);
    }


    return resultVector;
}

// @lc code=end

