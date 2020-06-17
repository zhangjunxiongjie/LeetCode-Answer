/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    void recursion(vector<vector<int>>& grid, int x, int y, int& area){
        if ((x + 1) < grid.size() && grid.at(x + 1).at(y) == 1)
        {
            area++;
            grid.at(x + 1).at(y) = 0;
            recursion(grid, x + 1, y, area);
        }
        if ((x - 1) >= 0 && grid.at(x - 1).at(y) == 1)
        {
            area++;
            grid.at(x - 1).at(y) = 0;
            recursion(grid, x - 1, y, area);
        }
        if (y + 1 < grid.at(0).size() && grid.at(x).at(y + 1) == 1)
        {
            area++;
            grid.at(x).at(y + 1) = 0;
            recursion(grid, x, y + 1, area);
        }
        if (y - 1 >= 0 && grid.at(x).at(y - 1) == 1)
        {
            area++;
            grid.at(x).at(y - 1) = 0;
            recursion(grid, x, y - 1, area);
        }
    }
    // 时间复杂度和空间复杂度不太理想。
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> tempGrid(grid);
        
        int maxArea = 0;
        for (int row = 0; row < tempGrid.size(); row++)
        {
            for (int line = 0; line < tempGrid.at(0).size(); line++)
            {
                if (tempGrid.at(row).at(line) == 1)
                {
                    tempGrid.at(row).at(line) = 0;
                    int area = 1;
                    recursion(tempGrid, row, line, area);
                    if (area > maxArea)
                    {
                        maxArea = area;
                    }
                }
            }
        }
        
        return maxArea;
    }
};
// @lc code=end

