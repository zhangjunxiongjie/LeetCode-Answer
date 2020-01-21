/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy = -1;
        // prices 容器为空时出错，prices.size()是一个无符号整数。
        for (int i = 0; i < int(prices.size()) - 1; i++)
        {
            if (prices.at(i) < prices.at(i + 1)) //
            {
                if (buy == -1) // 买入。
                {
                    buy = prices.at(i);
                }
            }
            else
            {
                if (buy != -1) // 卖出
                {
                    result += prices.at(i) - buy;
                    buy = -1; // 清仓。
                }
            }
        }
        if (buy != -1) // 仓库剩余。 
        {
            result += prices.at(prices.size() - 1) - buy;
            buy = -1;
        }
        return result;
    }
};
// @lc code=end

