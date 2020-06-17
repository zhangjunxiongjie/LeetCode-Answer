/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    // 真狠儿！！！
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        
        long int xVirtual = 0;
        int xChange = x;
        while (xChange != 0)
        {
            xVirtual = (xVirtual * 10) + (xChange % 10);
            xChange = xChange / 10;
        }
        return (x == xVirtual);
    }
};
// @lc code=end

