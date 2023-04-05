/*
 * @lc app=leetcode.cn id=2544 lang=c
 *
 * [2544] 交替数字和
 */

// @lc code=start
int alternateDigitSum(int n){

    int resultSum = 0;
    int resultSum1 = 0;

    bool nFlag = true;
    bool n1Flag = true;

    while (n) {

        int middle = (n % 10);

        if (nFlag) {
            nFlag = false;

            resultSum += middle;
        }
        else {
            nFlag = true;

            resultSum -= middle;
        }

        if (n1Flag) {
            n1Flag = false;

            resultSum1 -= middle;
        }
        else {
            n1Flag = true;

            resultSum1 += middle;
        }

        n /= 10;
    }

    if (!nFlag) {

        return resultSum;
    }
    else if (n1Flag) {

        return resultSum1;
    }

    return resultSum;
}

// @lc code=end

