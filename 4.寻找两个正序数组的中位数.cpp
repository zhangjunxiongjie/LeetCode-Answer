/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left1 = 0, right1 = nums1.size() - 1;
        int left2 = 0, right2 = nums2.size() - 1;
        
        while ((right1 - left1 + 1) + (right2 - left2 + 1) > 2 )
        {
            if (right1 >= left1 && right2 >= left2)
            {
                if (nums1.at(left1) < nums2.at(left2))
                {
                    left1++; // 
                }
                else
                {
                    left2++;
                }

                if (nums1.at(right1) < nums2.at(right2))
                {
                    right2--;
                }
                else
                {
                    right1--;
                }
                
            }
            else if(right1 >= left1)
            {
                left1++;
                right1--;
            }
            else if(right2 >= left2)
            {
                left2++;
                right2--;
            }
            else
            {
                // ???
            }
            
        }
        
        if (right1 == left1 && right2 == left2)
        {
            return (nums1.at(left1) + nums2.at(left2)) / 2.0; 
        }
        else if(left1 + 1 == right1)
        {
            return (nums1.at(left1) + nums1.at(right1)) / 2.0;
        }
        else if(left2 + 1 == right2)
        {
            return (nums2.at(left2) + nums2.at(right2)) / 2.0;
        }
        else if(right1 == left1)
        {
            return double(nums1.at(left1));
        }
        else if(right2 == left2)
        {
            return double(nums2.at(left2));
        }
        else
        {
            return 0.0; // ???
        }
        
    }
};
// @lc code=end

