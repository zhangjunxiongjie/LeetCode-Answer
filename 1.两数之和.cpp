/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> assis; // 辅助字典
        for (int i = 0; i < nums.size(); i++)
        {
            int middle = target - nums.at(i);
            auto iter = assis.find(nums.at(i));
            if (iter == assis.end())
            {
                assis.insert(pair<int, int> (middle, i));
            }
            else
            {
                nums.clear();
                nums.push_back(iter->second); // 
                nums.push_back(i);
                break;
            }
           
        }
        return nums;  
    } 
};

// @lc code=end

