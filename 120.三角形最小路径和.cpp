/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    // 只考虑左方影响时。
    int minimumTotal(vector<vector<int>>& triangle) {
        int result;
        vector<int> cache;
        for (int i = 0; i < triangle.size(); i++)
        {
            cache.push_back(0);
            for (int j = i; j >= 0; j--)
            {
                if (j != 0)
                {
                    if (j == i)
                    {
                        cache.at(j) = cache.at(j - 1);
                    }
                    else if (cache.at(j - 1) < cache.at(j))
                    {
                        cache.at(j) = cache.at(j - 1);
                    }
                }
                cache.at(j) += triangle.at(i).at(j);
                if (i == triangle.size() - 1)
                {
                    if (j == i)
                    {
                        result = cache.at(j);
                    }
                    else
                    {
                        if (cache.at(j) < result)
                        {
                            result = cache.at(j);
                        }
                    }
                }
                
            }
        }
        return result;
    }
};
// @lc code=end

