/*
 * @lc app=leetcode.cn id=492 lang=c
 *
 * [492] 构造矩形
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



int* constructRectangle(int area, int* returnSize){

    int areaSqrt = sqrt(area);
    int *resultVector = malloc(sizeof(int) * 2);

    (*returnSize) = 2;

    if ((areaSqrt * areaSqrt) == area) {

        resultVector[0] = areaSqrt;
        resultVector[1] = areaSqrt;

        return resultVector;
    }
    else {

        while ((area % areaSqrt) != 0) {

            areaSqrt--;
        }

        resultVector[0] = (area / areaSqrt);
        resultVector[1] = areaSqrt;

        return resultVector;
    }

}

// @lc code=end

