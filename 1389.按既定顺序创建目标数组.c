/*
 * @lc app=leetcode.cn id=1389 lang=c
 *
 * [1389] 按既定顺序创建目标数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    
    int *resultVector = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < indexSize; i++) {

        for (int j = 0; j < i; j++) {

            if (index[j] >= index[i]) {
                
                index[j]++;
            }
        }
    }

    for (int j = 0; j < indexSize; j++) {
        
        resultVector[index[j]] = nums[j];
    }

    (*returnSize) = numsSize;

    return resultVector;
}

// @lc code=end

