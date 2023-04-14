/*
 * @lc app=leetcode.cn id=1464 lang=c
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start


int maxProduct(int* nums, int numsSize){

    int firstMaxValue = 0;
    int secondMaxValue = 0;

    for (int *numsPointer = nums; numsPointer < (nums + numsSize); numsPointer++) {

        if ((*numsPointer) >= firstMaxValue) {

            secondMaxValue = firstMaxValue;
            firstMaxValue = (*numsPointer);

            // printf ("%d, %d, ", firstMaxValue, secondMaxValue);
        }
        else if ((*numsPointer) > secondMaxValue) {

            secondMaxValue = (*numsPointer);            
        }
    }

    return ((firstMaxValue - 1) * (secondMaxValue - 1));

    /*
    int maximum = 0;

    for (int i = 0; i < numsSize; i++) {

        for (int j = (i + 1); j < numsSize; j++) {

            int middle = ((nums[i] - 1) * (nums[j] - 1));
            if (maximum < middle) {
                
                maximum = middle;
            }
        }
    }

    return maximum;
    */
}

// @lc code=end

