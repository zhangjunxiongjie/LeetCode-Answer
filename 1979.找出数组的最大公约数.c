/*
 * @lc app=leetcode.cn id=1979 lang=c
 *
 * [1979] 找出数组的最大公约数
 */

// @lc code=start


int findGCD(int* nums, int numsSize){

    int minimumNum = 1001;
    int maximumNum = 0;

    for (int i = 0; i < numsSize; i++) {

        if (minimumNum > (*(nums + i))) {
            minimumNum = (*(nums + i));
        }

        if (maximumNum < (*(nums + i))) {
            maximumNum = (*(nums + i));
        }
    }
    
    // printf("%d, %d.\n", minimumNum, maximumNum);

    for (int i = minimumNum; i >= 1; i--) {
        
        if (((minimumNum % i) == 0) && (maximumNum % i) == 0) {

            return i;
        }
    }
    
    return 1;
}


// @lc code=end

