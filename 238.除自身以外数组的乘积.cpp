/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>& result = *new vector<int>;
        result.resize(nums.size());
        
        // 计算每个数的前缀乘积存放在result。
        result.at(0) = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            result.at(i) = result.at(i - 1) * nums.at(i - 1); 
        }

        // 将前缀乘积乘以后缀乘积。得到总乘积。
        int productBehind = 1; // 后缀总乘积
        for (int i = nums.size() - 1; i < nums.size(); i--)
        {
            result.at(i) = result.at(i) * productBehind;
            productBehind = productBehind * nums.at(i);
        }
        
        return result;
    }
};
// @lc code=end

