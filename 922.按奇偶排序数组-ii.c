/*
 * @lc app=leetcode.cn id=922 lang=c
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){

    int *evenPointer = nums;
    int *oddPointer = nums;
    int *numsIndex = nums;

    (*returnSize) = numsSize;

    while (numsIndex < (nums + numsSize)) {

        for (; ((evenPointer < (nums + numsSize)) && ((*evenPointer) % 2 == 1)); evenPointer++) {

            
        }

        if ((numsIndex < (nums + numsSize)) && 
            (evenPointer < (nums + numsSize))
        ) {

            if ((evenPointer != numsIndex)                 
            ) {

                int middle = (*evenPointer);
                (*evenPointer) = (*numsIndex);
                (*numsIndex) = middle;
                numsIndex++;
            }
            else {
                numsIndex++;
                evenPointer++;
            }
        }

        // for (int *numsPointer = nums; numsPointer < (nums + numsSize); numsPointer++) {

        //     printf ("%d, ", (*numsPointer));
        // }
        // printf ("\n");

        for (; ((oddPointer < (nums + numsSize)) && ((*oddPointer) % 2 == 0)); oddPointer++) {

            
        }

        if ((numsIndex < (nums + numsSize)) &&
            (oddPointer < (nums + numsSize))
        ) {

            if ((oddPointer != numsIndex)                 
            ) {
                
                int middle = (*oddPointer);
                (*oddPointer) = (*numsIndex);
                (*numsIndex) = middle;
                numsIndex++;
            }
            else {
                numsIndex++;
                oddPointer++;
            }
        }

        // for (int *numsPointer = nums; numsPointer < (nums + numsSize); numsPointer++) {

        //     printf ("%d, ", (*numsPointer));
        // }        
        // printf ("\n");
    }
    

    return nums;
}

// @lc code=end


