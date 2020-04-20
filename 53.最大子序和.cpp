/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = 0, sum = 0;
        int max = INT_MIN; // 记录最大值。
        for (int i = 0; i < nums.size(); i++) 
        {
            sum += nums.at(i);
            if (sum < 0)
            {
                sum = 0;
            }
            
            if (sum > maxsum)
            {
                maxsum = sum;
            }
            
            if (nums.at(i) > max) // 记录最大值，
            {
                max = nums.at(i);
            }
            
        }

        if (max < 0)  // 如果最大值都小于零说明不存在整数和零。
        {
            maxsum = max;
        }
        
        return maxsum;
    }
};
// @lc code=end

