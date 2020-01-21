/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    // 有待优化。时间复杂度较高。
    int maxProfit1(vector<int>& prices, int left, int right) {
        int result = 0;
        int max = 0; // 记录最大者。
        for (int i = right - 1; i >= left; i--)
        {
            if (max < prices.at(i))
            {
                max = prices.at(i);
            }
            if (max - prices.at(i) > result)
            {
                result = max - prices.at(i);
            }
        }
        return result;
    }

    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            // 包括左边不包括右边。
            int buffer = maxProfit1(prices, 0, i) + maxProfit1(prices, i, prices.size());
            if (i == 0 && buffer == 0) // 特殊情况！股价只降不升。
            {
                return 0;
            }
            if (buffer > result)
            {
                result = buffer;
            }
        }
        return result;
    }
};
// @lc code=end

