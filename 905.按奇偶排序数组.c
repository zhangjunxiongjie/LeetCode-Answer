/*
 * @lc app=leetcode.cn id=905 lang=c
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){

    int *leftP = nums;
    int *rightP = nums + (numsSize - 1);

    (*returnSize) = numsSize;

    while (true) {

        while (((*leftP) % 2 == 0) && (leftP < rightP)) {

            leftP++;            
        }

        while (((*rightP) % 2 == 1) && (leftP < rightP)) {
            
            rightP--;
        }

        if (leftP < rightP) {

            int temp = (*leftP);

            (*leftP) = (*rightP);
            (*rightP) = temp;
        }
        else {
            break;
        }
    }

    return nums;
}


// @lc code=end

