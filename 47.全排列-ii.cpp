/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// 未通过，如何进行无重复的全排列？
// @lc code=start
class Solution {
public:
    
    void swop(int left, int right, vector<int>& nums){
        int middle = nums.at(left);
        nums.at(left) = nums.at(right);
        nums.at(right) = middle;
    }

    void recursion(vector<vector<int>>& result, vector<int>& nums, int flag){
        int last = -1;
        for (int i = flag + 1; i < nums.size(); i++)
        {
            if (nums.at(flag) != nums.at(i) && last != nums.at(i))
            {
                last = nums.at(i);

                swop(flag, i, nums);
                result.push_back(nums);
                recursion(result, nums, flag + 1);
                swop(flag, i, nums);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        result.push_back(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            recursion(result, nums, i);
        }
        
        return result;
    }
};
// @lc code=end

