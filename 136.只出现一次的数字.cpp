/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            result ^= *iter;
        }
        return result;
    }
};
// @lc code=end

