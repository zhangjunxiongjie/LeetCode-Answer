/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    // 超时。
    int rangeBitwiseAnd(int m, int n) {
        if (m == INT_MAX)
        {
            return m;
        }
        
        int result = m;
        // 当n == INT_MAX时加一变成INT_MIN依然不会退出循环。 
        for (int i = m + 1; i <= n; i++)
        {
            result = result & i;
            if (result == 0 || i == INT_MAX) 
            {
                break;
            }
        }
        return result;
    }
};


// @lc code=end

