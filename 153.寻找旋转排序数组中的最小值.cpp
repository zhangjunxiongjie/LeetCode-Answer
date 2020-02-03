/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    // 二分查找。
    int findMin(vector<int>& nums) {

        if (nums.size() == 1) // 只有一个元素时。
        {
            return nums.at(0);
        }
        else if (nums.at(0) < nums.at(1) && nums.at(0) < nums.at(nums.size() - 1)) // 最小值在第一个元素时。
        {
            return nums.at(0);
        }
        else if (nums.at(nums.size() - 1) < nums.at(0) && nums.at(nums.size() - 1) < nums.at(nums.size() - 2)) // 最小值在最后一个元素时。
        {
            return nums.at(nums.size() - 1);
        }
        
        int left = 1, right = nums.size() - 1; // 
        int middle = (left + right) / 2;
        while (true)
        {
            if (nums.at(middle) < nums.at(middle + 1) && nums.at(middle) < nums.at(middle - 1))
            {
                return nums.at(middle);
            }
            else if (nums.at(middle) > nums.at(0))
            {
                left = middle;
            }
            else if (nums.at(middle) < nums.at(nums.size() - 1))
            {
                right = middle;
            }
            
            middle = (left + right) / 2;
        }

    }
};
// @lc code=end

