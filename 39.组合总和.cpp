/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// 问题的关键在于如何确定某一个数的个数？
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>& result = *new vector<vector<int>>;

        // 排序。
        for (int i = 0; i < candidates.size(); i++)
        {
            for (int j = i + 1; j < candidates.size(); j++)
            {
                if (candidates.at(i) > candidates.at(j))
                {
                    int middle = candidates.at(i);
                    candidates.at(i) = candidates.at(j);
                    candidates.at(j) = middle;
                }
                
            }
            
        }


        // result.push_back(candidates);
        return result;
    }
};
// @lc code=end

