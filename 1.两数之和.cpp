/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> diction; // 辅助字典
        vector<int> result; // 
        for (int i = 0; i < nums.size(); i++)
        {
            int middle = target - nums.at(i);
            auto iter = diction.find(nums.at(i));
            if (iter == diction.end())
            {
                diction.insert(pair<int, int> (middle, i));
            }
            else
            {
                result.push_back(iter->second); // 
                result.push_back(i);
                break;
            }
            
        }
        return result;  
    } 
    
};

// @lc code=end

