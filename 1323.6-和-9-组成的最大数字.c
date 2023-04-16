/*
 * @lc app=leetcode.cn id=1323 lang=c
 *
 * [1323] 6 和 9 组成的最大数字
 */

// @lc code=start


int maximum69Number (int num) {

    int resultTarget = 0;
    bool resultFlag = true;

    while (num) {
        
        resultTarget = (resultTarget * 10) + (num % 10);
        num /= 10;
    }

    while (resultTarget) {

        if ((resultFlag) && ((resultTarget % 10) == 6)) {

            resultFlag = false;

            num = (num * 10) + 9;
            resultTarget /= 10;
        }
        else {

            num = (num * 10) + (resultTarget % 10);             
            resultTarget /= 10;
        }

    }
    
    resultTarget = num;

    return resultTarget;
}

// @lc code=end

