/*
 * @lc app=leetcode.cn id=1009 lang=c
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start


int bitwiseComplement(int n){

    int resultTarget = 0;
    int resultCounter = 0;

    do {

        if ((n % 2) != 1) {

            resultTarget |= (1 << resultCounter);
        }        
        
        n >>= 1;
        resultCounter++;
    }
    while (n);

    return resultTarget;
}

// @lc code=end

