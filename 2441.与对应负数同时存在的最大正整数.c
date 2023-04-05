/*
 * @lc app=leetcode.cn id=2441 lang=c
 *
 * [2441] 与对应负数同时存在的最大正整数
 */

// @lc code=start

bool isSubset(int *nums, int numsSize, int target)
{
    int numsLeftIndex = 0;
    int numsRightIndex = (numsSize - 1);

    do
    {
        int middle = (numsLeftIndex + numsRightIndex) / 2;

        if (nums[numsLeftIndex] == target) {
            return true;
        }

        if (nums[numsRightIndex] == target) {
            return true;
        }

        if (nums[middle] == target) {
            return true;
        }
        else if (nums[middle] < target) {
            numsLeftIndex = middle;            
        }
        else if (nums[middle] > target) {
            numsRightIndex = middle;
        }
        
    }
    while (numsLeftIndex < (numsRightIndex - 1));

    return false;
}

int findMaxK(int* nums, int numsSize){

    for (int i = 0; i < numsSize; i++) {
        
        int targetIndex = i;

        for (int j = (i + 1); j < numsSize; j++) {

            if (nums[targetIndex] > nums[j]) {
                
                targetIndex = j;
            }
        }

        // printf ("%d, %d\n", nums[targetIndex], nums[i]);

        if (targetIndex != i) {
            
            // nums[targetIndex] = nums[targetIndex] ^ nums[i];
            // nums[i] = (nums[i] ^ nums[targetIndex]);
            // nums[targetIndex] = (nums[i] ^ nums[targetIndex]);

            int middle = nums[targetIndex];
            nums[targetIndex] = nums[i];
            nums[i] = middle;
        }

        // printf ("%d, %d\n", nums[targetIndex], nums[i]);
        // printf ("%d, \n", nums[i]);
    }
    
    for (int i = (numsSize - 1); i >= 0; i--) {

        if ((nums[i] > 0) && isSubset(nums, numsSize, (-nums[i]))) {

            return nums[i];
        }
    }
    

    return -1;
}

// @lc code=end

