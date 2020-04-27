/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void overturn(vector<int>& nums, int left, int right){
        for (int i = left, j = right - 1; i < j; i++, j--)
        {
            int middle = nums.at(i);
            nums.at(i) = nums.at(j);
            nums.at(j) = middle;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        // 整个翻转，
        overturn(nums, 0, nums.size());
        // 翻转前k个，
        overturn(nums, 0, k);
        // 翻转后面
        overturn(nums, k, nums.size());
    }
};

// @lc code=end

