/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    // 不懂！！！一脸懵逼。
    int singleNumber(vector<int>& nums) {
        int a = 0,b = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            b = (b ^ *iter) & ~a;
            a = (a ^ *iter) & ~b;
        }
        
        return b;
    }
};
// @lc code=end

