/*
 * @lc app=leetcode.cn id=507 lang=c
 *
 * [507] 完美数
 */

// @lc code=start


bool checkPerfectNumber(int num){

    int numSqrt = sqrt(num);
    long int numSum = 0;

    while (numSqrt > 0) {

        if ((num % numSqrt) == 0) {

            numSum += numSqrt;
            numSum += (num / numSqrt);            
        }

        numSqrt--;
    }

    if (((numSum % num) == 0) && ((numSum / 2) == num) && (num != 1)) {

        return true;
    }

    return false;
}

// @lc code=end

