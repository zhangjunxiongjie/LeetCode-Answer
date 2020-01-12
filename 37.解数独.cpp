/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    
    // 递归填充。
    bool recurfill(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& line, vector<vector<int>>& matrix, int i, int j)
    {
        for (int x = 1; x <= 9; x++)
        {
            if (row.at(i).at(x) && line.at(j).at(x) && matrix.at((i - i % 3) + (j - j % 3) / 3).at(x) )
            {
                // 尝试填充。
                board.at(i).at(j) = x + '0';
                row.at(i).at(x) = 0;
                line.at(j).at(x) = 0;
                matrix.at((i - i % 3) + (j - j % 3) / 3).at(x) = 0;

                // 查找下一个填充位置。
                int z = i * 9 + j + 1;
                for (; z < 81; z++)
                {
                    if(board.at(z / 9).at(z % 9) == '.')
                    {
                        if (recurfill(board, row, line, matrix, z / 9, z % 9))
                            return true;
                        
                        break;
                    }
                }
                if (z == 81) // 如果所有位置都不为空。
                    return true;
                
                // 还原。
                board.at(i).at(j) = '.';
                row.at(i).at(x) = 1;
                line.at(j).at(x) = 1;
                matrix.at((i - i % 3) + (j - j % 3) / 3).at(x) = 1;

            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row, line, matrix; // 记录每一行列矩阵的限制

        // 初始化
        vector<int> buffer;
        for (int i = 0; i <= 9; i++)
        {
            buffer.push_back(1); //未使用
        }
        for (int i = 0; i < 9; i++)
        {
            row.push_back(buffer);
            line.push_back(buffer);
            matrix.push_back(buffer);
        }
        


        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board.at(i).at(j);
                if (ch != '.')
                {
                    // 已使用。（限制）
                    row.at(i).at(ch - '0') = 0;
                    line.at(j).at(ch - '0') = 0;
                    matrix.at((i - i % 3) + (j - j % 3) / 3).at(ch - '0') = 0;
                }
            }
        }

        
        for (int z = 0; z < 81; z++)
        {
            if(board.at(z / 9).at(z % 9) == '.')
            {
                // 利用限制条件递归填充空位置。
                recurfill(board, row, line, matrix, z / 9, z % 9);
                return ;
            }
        }

    }
};
// @lc code=end

