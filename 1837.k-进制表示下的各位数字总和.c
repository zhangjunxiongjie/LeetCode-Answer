/*
 * @lc app=leetcode.cn id=1837 lang=c
 *
 * [1837] K 进制表示下的各位数字总和
 */

// @lc code=start


int sumBase(int n, int k){

    int resultSum = 0;

    while (n != 0) {

        resultSum += (n % k);
        
        n /= k;
    }

    return resultSum;
}

// @lc code=end

