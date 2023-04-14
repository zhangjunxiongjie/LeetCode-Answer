/*
 * @lc app=leetcode.cn id=1732 lang=c
 *
 * [1732] 找到最高海拔
 */

// @lc code=start


int largestAltitude(int* gain, int gainSize){

    int resultMaximum = 0;
    int middleValue = 0;

    for (int i = 0; i < gainSize; i++) {

        middleValue = middleValue + gain[i];

        if (middleValue > resultMaximum) {

            resultMaximum = middleValue;
        }
    }

    return resultMaximum;
}

// @lc code=end

