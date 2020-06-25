/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    // 牛逼的算法思维。
    int rangeBitwiseAnd(int m, int n) {
        int zeroCount = 0;
        while (n != m)
        {
            n = n >> 1;
            m = m >> 1;
            zeroCount++;
        }
        return (m << zeroCount);
    }
};


// @lc code=end

