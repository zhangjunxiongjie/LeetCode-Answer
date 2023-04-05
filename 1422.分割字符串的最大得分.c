/*
 * @lc app=leetcode.cn id=1422 lang=c
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start


int maxScore(char * s){

    int resultSum = 0;
    int resultMax = 0;
    int oneCounter = 0;
    int zeroCounter = 0;

    for (char *strPointer = s; strPointer < (s + strlen(s)); strPointer++) {

        if ((*strPointer) == '0') {

            zeroCounter++;
        }
        else if ((*strPointer) == '1') {

            oneCounter++;
        }
    }

    resultSum = oneCounter;

    for (char *strPointer = s; strPointer < (s + strlen(s) - 1); strPointer++) {

        if ((*strPointer) == '0') {
            
            resultSum++;
        }
        else if ((*strPointer) == '1') {

            resultSum--;
        }

        if (resultSum > resultMax) {
            
            resultMax = resultSum;
        }
    }

    return resultMax;
}

// @lc code=end

