/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    // 递归实现时间复杂度较高。
    void explore(vector<vector<char>>& grid, int x, int y){
        if (x - 1 >= 0 && grid.at(x - 1).at(y) == '1')
        {
            grid.at(x - 1).at(y) = '0';
            explore(grid, x - 1, y);
        }
        if (y - 1 >= 0 && grid.at(x).at(y - 1) == '1')
        {
            grid.at(x).at(y - 1) = '0';
            explore(grid, x, y - 1);
        }
        if (x + 1 < grid.size() && grid.at(x + 1).at(y) == '1')
        {
            grid.at(x + 1).at(y) = '0';
            explore(grid, x + 1, y);
        }
        if (y + 1 < grid.at(0).size() && grid.at(x).at(y + 1) == '1')
        {
            grid.at(x).at(y + 1) = '0';
            explore(grid, x, y + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.at(0).size(); j++)
            {
                if (grid.at(i).at(j) == '1')
                {
                    grid.at(i).at(j) = '0';
                    explore(grid, i, j);
                    result++;
                }
            }
        }

        return result;
    }
};
// @lc code=end

