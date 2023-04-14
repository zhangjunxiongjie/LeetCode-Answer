/*
 * @lc app=leetcode.cn id=1716 lang=c
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start


int totalMoney(int n) {

    int resultSum = 0;
    int nDivisor = (n / 7);
    int nRemainder = (n % 7);

    for (int i = 1; i <= (nDivisor); i++) {

        resultSum += ((i + 3) * 7);
    }
    
    for (int i = 1; i <= (nRemainder); i++) {
        
        resultSum += (i + (nDivisor));
    }

    return resultSum;
}

// @lc code=end

