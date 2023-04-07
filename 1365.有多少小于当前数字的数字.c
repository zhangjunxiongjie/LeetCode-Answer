/*
 * @lc app=leetcode.cn id=1365 lang=c
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getIndex(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = (numsSize - 1);
    int middle = ((left + right) / 2);

    while (left < right) {

        if (nums[left] == target) {

            return left;
        }
        if (nums[right] == target) {

            return right;
        }

        if (nums[middle] == target) {

            return middle;
        }
        else if (nums[middle] < target) {

            left = middle;
        }
        else if (nums[middle] > target) {

            right = middle;
        }

        middle = ((left + right) / 2);
    }

    return -1;
}


int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){   
    int *numsAssistant = malloc(sizeof(int) * numsSize);
    int *numsCache = malloc(sizeof(int) * numsSize);
    int *numsResult = malloc(sizeof(int) * numsSize);
    
    memcpy(numsAssistant, nums, (sizeof(int) * numsSize));

    memset(numsCache, 0, (sizeof(int) * numsSize));
    memset(numsResult, 0, (sizeof(int) * numsSize));

    for (int i = 0; i < numsSize; i++) {

        int target = i;
        for (int j = (target + 1); j < numsSize; j++) {
            
            if (nums[target] > nums[j]) {
                
                target = j;
            }
        }

        if (target != i) {
            
            nums[target] ^= nums[i];
            nums[i] ^= nums[target];
            nums[target] ^= nums[i];
        }
        
        if (((i - 1) >= 0)) {

            if (nums[i - 1] == nums[i]) {
                
                numsResult[i] = numsResult[i - 1];
            }
            else {

                numsResult[i] = i;
            }
        }
        else {

            numsResult[i] = i;
        }
        
    }

    
    for (int i = 0; i < numsSize; i++) {

        int target = getIndex(nums, numsSize, numsAssistant[i]);
        
        // printf ("%d, %d, %d, %d\n", i, numsAssistant[i], target, nums[i]);
        
        if ((target != -1)) {

            numsCache[i] = numsResult[target];
        }
        
    }
    
    free(numsAssistant);
    free(numsResult);

    (*returnSize) = numsSize;
    return numsCache;

    /*
    int *numsAssistant = malloc(sizeof(int) * 101);

    memset(numsAssistant, 0, (sizeof(int) * 101));

    for (int i = 0; i < numsSize; i++) {

        numsAssistant[nums[i]]++;
    }

    int assistantSum = 0;
    for (int i = 0; i < 101; i++) {

        int middle = numsAssistant[i];
        numsAssistant[i] = assistantSum;
        assistantSum += middle;
    }

    for (int i = 0; i < numsSize; i++) {

        nums[i] = numsAssistant[nums[i]];    
    }

    free(numsAssistant);

    (*returnSize) = numsSize;
    return nums;
    */
}

// @lc code=end

