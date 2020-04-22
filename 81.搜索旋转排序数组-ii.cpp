/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        if (nums.size() == 0)
        {
            return false;
        }
        else if(target == nums.at(nums.size() - 1))
        {
            return true;
        }
        else
        {
            while (left < right)
            {
                if (nums.at(left) == target || nums.at(right) == target)
                {
                    return true;
                }
                else if(left + 1 == right)
                {
                    return false;
                }
                
                int middle = (left + right) / 2;
                
                if(nums.at(middle) == target)
                {
                    return true;
                }
                else if (nums.at(middle) > target && target > nums.at(nums.size() - 1))
                {
                    right = middle;
                }
                else if (nums.at(middle) < target && target < nums.at(nums.size() - 1))
                {
                    left = middle;
                }
                else
                {
                    if (nums.at(middle) < nums.at(nums.size() - 1)) // middle 在左边。
                    {
                        right = middle;
                    }
                    else if(nums.at(middle) > nums.at(nums.size() - 1)) // middle 在右边
                    {
                        left = middle;
                    }
                    else // middle 可能在左边也可能在右边。
                    {
                        left++;
                    }
                }
                
            }
            
        }

        return false;
    }
};
// @lc code=end

