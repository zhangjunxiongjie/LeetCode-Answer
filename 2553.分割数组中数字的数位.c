/*
 * @lc app=leetcode.cn id=2553 lang=c
 *
 * [2553] 分割数组中数字的数位
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void judgeDigits(int* num, int* digitCounter)
{
    int middle = 0;

    while ((*num) != 0) {

        middle |= (((*num) % 10) + 1);
        middle <<= 4;
        
        (*num) /= 10;     

        (*digitCounter)++;
    }

    (*num) = middle;

    return ;
}

int* separateDigits(int* nums, int numsSize, int* returnSize){
    
    int digitSum = 0;

    for (int i = 0; i < numsSize; i++) {

        judgeDigits(&nums[i], &digitSum);
    }
    
    int *digitVector = malloc(sizeof(int) * (digitSum));
    int *digitVectorPointer = digitVector;
    for (int i = 0; i < numsSize; ) {

        int middle = (nums[i] & 0x0000000F);
        nums[i] >>= 4;

        if (middle != 0) {

            (*digitVectorPointer) = (middle - 1);
            digitVectorPointer++; 
        }        

        if (nums[i] == 0) {

            i++;
        }
    }

    (*returnSize) = digitSum;
    return digitVector;
}

// @lc code=end

