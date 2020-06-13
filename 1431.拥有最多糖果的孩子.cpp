/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> vecBool = *new vector<bool>;
        int max = 0;
        for (auto iter = candies.begin(); iter != candies.end(); ++iter)
        {
            if (*iter > max)
            {
                max = *iter;
            }
        }
        for (auto iter = candies.begin(); iter != candies.end(); ++iter)
        {
            if(*iter + extraCandies >= max)
            {
                vecBool.push_back(true);
            }
            else
            {
                vecBool.push_back(false);
            }
        }
        return vecBool;
    }
};
// @lc code=end

