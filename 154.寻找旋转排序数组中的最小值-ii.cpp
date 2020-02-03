/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if (nums.size() == 1) // 只有一个元素时。
        {
            return nums.at(0);
        }
        else if (nums.at(0) <= nums.at(1) && nums.at(0) < nums.at(nums.size() - 1)) // 最小值在第一个元素时。
        {
            return nums.at(0);
        }
        else if (nums.at(nums.size() - 1) <= nums.at(0) && nums.at(nums.size() - 1) < nums.at(nums.size() - 2)) // 最小值在最后一个元素时。
        {
            return nums.at(nums.size() - 1);
        }
        
        int left = 1, right = nums.size() - 1; // 
        int middle = (left + right) / 2;
        while (left + 1 < right)
        {
            if (nums.at(middle) <= nums.at(middle + 1) && nums.at(middle) < nums.at(middle - 1))
            {
                return nums.at(middle);
            }
            else if(nums.at(middle) == nums.at(0) && nums.at(0) == nums.at(nums.size() - 1)) // 特殊情况。
            {
                int i = middle - 1;
                for (; i >= 0; i--)
                {
                    if (nums.at(i) != nums.at(middle))
                    {
                        right = middle;
                        break;
                    }
                }
                if (i == -1)
                {
                    left = middle;
                }
            }
            else if (nums.at(middle) >= nums.at(0)) // 先排除特殊情况。
            {
                left = middle;
            }
            else if (nums.at(middle) <= nums.at(nums.size() - 1))
            {
                right = middle;
            }
            
            middle = (left + right) / 2;
        }

        if (nums.at(left) < nums.at(right)) // 所有元素相同时。
        {
            return nums.at(left);
        }
        else
        {
            return nums.at(right);
        }
        
    }
};
// @lc code=end

