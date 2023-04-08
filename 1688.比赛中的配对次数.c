/*
 * @lc app=leetcode.cn id=1688 lang=c
 *
 * [1688] 比赛中的配对次数
 */

// @lc code=start


int numberOfMatches(int n){

    int resultCounter = 0;

    while (n != 1) {

        if (n & 1) {

            resultCounter += ((n - 1) / 2);
            n = (n - 1) / 2 + 1;
        }
        else {

            resultCounter += (n / 2);
            n /= 2;
        }
    }

    return resultCounter;
}

// @lc code=end

