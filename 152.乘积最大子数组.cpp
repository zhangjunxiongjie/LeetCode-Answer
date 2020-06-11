/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
public:
    // 动态规划！！！
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        
        int maxProduct = 1;
        int minProduct = 1;
        for (int i = 0; i < nums.size(); i++)
        {            
            if (nums.at(i) < 0)
            {
                int temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }
            
            maxProduct = (maxProduct * nums.at(i)) > nums.at(i) ? (maxProduct * nums.at(i)) : nums.at(i);
            
            minProduct = (minProduct * nums.at(i)) < nums.at(i) ? (minProduct * nums.at(i)) : nums.at(i);
            
            // cout << minProduct << ":" << maxProduct << endl;

            result = maxProduct > result ? maxProduct : result;
        }
        
        return result;
    }
};
// @lc code=end

