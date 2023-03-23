/*
 * @lc app=leetcode.cn id=2119 lang=c
 *
 * [2119] 反转两次的数字
 */

// @lc code=start


bool isSameAfterReversals(int num){
    /*
    int middleBuffer[7];
    int middleValue;
    int middleCache;
    int middleNum = num;
    int index;

    for (index = 0; index < 7; index++) {

        middleBuffer[index] = 0;
    }
    //----------------------------------------
    index = 0;
    while (num != 0) {

        middleBuffer[index++] = (num % 10);
        num /= 10;

        // printf ("%d\n", middleBuffer[index - 1]);
    }

    middleValue = 0;
    middleCache = index;
    for (; index > 0; index--) {

        middleValue = (middleValue * 10) + middleBuffer[middleCache - index];

        // printf ("%d\n", middleValue);
    }

    //----------------------------------------
    index = 0;
    num = middleValue;
    while (num != 0) {

        middleBuffer[index++] = (num % 10);
        num /= 10;
    }

    middleValue = 0;
    middleCache = index;
    for (; index > 0; index--) {

        middleValue = (middleValue * 10) + middleBuffer[middleCache - index];
    }
    //----------------------------------------
    // printf ("%d, %d\n", middleValue, middleNum);

    return (middleValue == middleNum);
    */

    if ((num >= 10) && ((num % 10) == 0)) {

        return false;
    }
    else {

        return true;
    }

}

// @lc code=end

