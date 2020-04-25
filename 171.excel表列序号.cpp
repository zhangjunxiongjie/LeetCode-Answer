/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result = result * 26 + (s.at(i) - 64);
        }
        return result;
    }
};
// @lc code=end

