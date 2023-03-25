/*
 * @lc app=leetcode.cn id=2469 lang=c
 *
 * [2469] 温度转换
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize){

    double *resultVector = malloc(sizeof(double) * 2);
    (*returnSize) = 2;

    resultVector[0] = celsius + ((double)273.15);
    resultVector[1] = (celsius * ((double)1.80) + ((double)32.00));

    return resultVector;
}

// @lc code=end

