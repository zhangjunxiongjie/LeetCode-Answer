/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>& result = *new vector<int>;
        if (matrix.size() == 0)
        {
            return result;
        }

        int rowMax = matrix.size();
        int lineMax = matrix[0].size();
        int rowMin = 0;
        int lineMin = 0; 

        while ((rowMin < rowMax) && (lineMin < lineMax))
        {
            int row = rowMin;
            int line = lineMin;

            // line++
            for (; line < lineMax; line++)
            {
                result.push_back(matrix[row][line]);
            }
            rowMin++;
            if (rowMin >= rowMax)
            {
                break;
            }
            
            // row++
            for (line -= 1, row += 1; row < rowMax; row++)
            {
                result.push_back(matrix[row][line]);
            }
            lineMax--;
            if (lineMin >= lineMax)
            {
                break;
            }

            // line--
            for (row -= 1, line -= 1; line >= lineMin; line--)
            {
                result.push_back(matrix[row][line]);
            }
            rowMax--;
            if (rowMin >= rowMax)
            {
                break;
            }

            // row--
            for (line += 1, row -= 1; row >= rowMin; row--)
            {
                result.push_back(matrix[row][line]);
            }
            lineMin++;
            
        }

        return result;
    }
};
// @lc code=end

