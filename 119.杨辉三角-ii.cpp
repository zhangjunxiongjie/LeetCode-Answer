/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        for (int i = 1; i <= rowIndex; i++)
        {
            result.push_back(0);
            for (int j = i; j > 0; j--)
            {
                result.at(j) += result.at(j - 1);
            }
        }
        return result;
    }
};
// @lc code=end

