/*
 * @lc app=leetcode.cn id=2520 lang=c
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
int countDigits(int num){
    
    int digitCounter = 0;
    int middle = num;

    while (middle) {

        if ((num % (middle % 10)) == 0) {

            digitCounter++;
        }

        middle /= 10;
    }

    return digitCounter;
}

// @lc code=end

