/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        result.resize(numRows);
        for (int i = 1; i <= numRows; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j == 1 || j == i)
                {
                    result.at(i - 1).push_back(1);
                }
                else
                {
                    int sum = result.at(i - 2).at(j - 2) + result.at(i - 2).at(j - 1);
                    result.at(i - 1).push_back(sum);
                }
            }
        }
        return result;
    }
};
// @lc code=end

