/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int max = 0; // 记录最大者。
        for (int i = prices.size() - 1; i >= 0; i--)
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
};
// @lc code=end

