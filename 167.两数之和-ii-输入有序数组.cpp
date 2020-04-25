/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>& index = *new vector<int>;
        index.push_back(0);
        index.push_back(numbers.size() - 1);
        
        while (index.at(0) < index.at(1))
        {
            int sum = numbers.at(index.at(0)) + numbers.at(index.at(1));
            if (sum > target)
            {
                index.at(1)--;
            }
            else if (sum < target)
            {
                index.at(0)++;
            }
            else
            {
                break;
            }
        }
        index.at(0)++;
        index.at(1)++;

        return index;
    }
};
// @lc code=end

