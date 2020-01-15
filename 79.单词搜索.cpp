/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    // 深度优化搜索。
    bool deepsearch(vector<vector<char>>& board, string& word, vector<vector<int>>& turn, int x, int y, int iter)
    {
        if (iter == word.size())
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int xr = x + turn.at(i).at(0);
            int yr = y + turn.at(i).at(1);

            if ((xr >= 0 && xr < board.size()) && (yr >= 0 && yr < board.at(0).size()) && board.at(xr).at(yr) != 0 && board.at(xr).at(yr) == word.at(iter))
            {
                board.at(xr).at(yr) = 0; // 已经使用过。
                if (deepsearch(board, word, turn, xr, yr, iter + 1))
                {
                    return true;
                }
                board.at(xr).at(yr) = word.at(iter); // 还原。
            }
        }
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
        {
            return false;
        }
        
        bool result = false;
        vector<vector<int>> turn = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        // 寻找起始位置。
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.at(0).size(); j++)
            {
                if (board.at(i).at(j) == word.at(0) && !result)
                {
                    board.at(i).at(j) = 0; // 已经使用过。
                    result = deepsearch(board, word, turn, i, j, 1);
                    board.at(i).at(j) = word.at(0); // 还原。
                }
            }
            if (result)
            {
                break;
            }
        }

        return result;
    }

};
// @lc code=end

