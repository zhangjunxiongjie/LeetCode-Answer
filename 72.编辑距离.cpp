/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    // 模糊匹配算法（德雷曼-温施算法）
    // 使用动态规划利用辅助矩阵计算编辑距离。
    // 插入，删除，替换的得分是+1，匹配的得分是0.
    int minDistance(string word1, string word2) {
        int matrixrow = word1.size() + 1;
        int matrixline = word2.size() + 1;

        // 组织辅助矩阵。(简化版辅助矩阵)
        // 辅助矩阵还可以简化一层。
        vector<vector<int>> cache;
        vector<int> buffer;
        for (int i = 0; i < matrixrow; i++)
        {
            buffer.push_back(i);
        }
        for (int i = 0; i < matrixline; i++)
        {
            buffer.at(0) = i;
            cache.push_back(buffer);
        }
        
        for (int i = 1; i < matrixline; i++)
        {
            for (int j = 1; j < matrixrow; j++)
            {
                int may1 = cache.at(i).at(j - 1) + 1;
                int may2 = cache.at(i - 1).at(j) + 1;
                int may3;
                if (word1.at(j - 1) == word2.at(i - 1))
                {
                    may3 = cache.at(i - 1).at(j - 1);
                }
                else
                {
                    may3 = cache.at(i - 1).at(j - 1) + 1;
                }
                int may;
                // 找最小的匹配距离。
                if(may3 <= may2 && may3 <= may1)
                {
                    may = may3;
                }              
                else if (may2 <= may3 && may2 <= may1)
                {
                    may = may2;
                }
                else
                {
                    may = may1;
                }
                
                cache.at(i).at(j) = may;
            }
            
        }

        return cache.at(matrixline - 1).at(matrixrow - 1);
    }
};
// @lc code=end

