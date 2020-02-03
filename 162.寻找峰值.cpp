/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    // 有待优化。
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        else if(nums.at(0) > nums.at(1)) // 第一个元素是峰值元素。
        {
            return 0; 
        }
        else if (nums.at(nums.size() - 1) > nums.at(nums.size() - 2)) // 最后一个元素是峰值元素。
        {
            return nums.size() - 1;
        }
        
        int left = 1, right = nums.size() - 1;
        int middle = (left + right) / 2;
        bool flag = true;
        while (flag || left + 1 < right)
        {
            if (left + 1 >= right)
            {
                flag = false;
            }
            
            if (nums.at(middle) > nums.at(middle - 1) && nums.at(middle) > nums.at(middle + 1))
            {
                return middle;
            }
            else if (nums.at(middle) < nums.at(middle - 1))
            {
                right = middle;
            }
            else if(nums.at(middle) < nums.at(middle + 1))
            {
                left = middle;
            }
            middle = (left + right) / 2;
            
        }
        return right;
    }
};
// @lc code=end

