/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */

// @lc code=start
class Solution {
public:
    // 投票算法。
    int majorityElement(vector<int>& nums){
        int majority;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                majority = nums.at(i);
                count++;
            }
            else if(majority == nums.at(i))
            {
                count++;
            }
            else if(majority != nums.at(i))
            {
                count--;
            }
        }
        return majority;
    }
    /*
    // 时间复杂度较差。
    int majorityElement(vector<int>& nums) {
        int majority;
        int same = INT_MIN;
        while (nums.size() >= 3)
        {
            same = nums.at(nums.size() - 1);
            nums.pop_back();
            for (auto iter = nums.begin(); iter != nums.end(); iter++)
            {
                if (*iter != same)
                {
                    nums.erase(iter);
                    break;
                }
            }
            
        }
        majority = nums.at(0);
        return majority;
    }
    */
};
// @lc code=end

