/*
 * @lc app=leetcode.cn id=693 lang=c
 *
 * [693] 交替位二进制数
 */

// @lc code=start


bool hasAlternatingBits(int n){

    while (n != 0) {

        if ((n & 1) && ((n >> 1) & 1)) {

            return false;
        } 

        if (!(n & 1) && !((n >> 1) & 1)) {
            
            return false;
        }

        n >>= 1;
    }

    return true;
}

// @lc code=end

