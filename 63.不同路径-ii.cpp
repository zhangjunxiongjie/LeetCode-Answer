/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    // 深度优化寻路。 超时！！！
    void recursion(vector<vector<int>> obstacleGrid, vector<vector<int>>& turn, int& sum, int x, int y)
    {
        int xmax = obstacleGrid.size() - 1;
        int ymax = obstacleGrid.at(0).size() - 1;
        
        if (x == xmax && y == ymax)
        {
            sum++;
            return ;
        }
        
        for (int i = 0; i < turn.size(); i++)
        {
            int xr = x + turn.at(i).at(0);
            int yr = y + turn.at(i).at(1);
            if ((xr >= 0 && xr <= xmax) && (yr >= 0 && yr <= ymax) && obstacleGrid.at(xr).at(yr) == 0)
            {
                obstacleGrid.at(xr).at(yr) = 1;
                recursion(obstacleGrid, turn, sum, xr, yr);
                obstacleGrid.at(xr).at(yr) = 0;
            }
            
        }
        
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 转向，只能向两个方向转向。
        vector<vector<int>> turn = {{0, 1}, {1, 0}}; 
        int result = 0;
        // 特殊情况
        if (obstacleGrid.empty())
        {
            return 0;
        }
        else if(obstacleGrid.at(0).empty())
        {
            return 1;
        }
        else if(obstacleGrid.at(0).at(0) == 1)
        {
            return 0;
        }
        else if(obstacleGrid.at(obstacleGrid.size() - 1).at(obstacleGrid.at(0).size() - 1) == 1)
        {
            return 0;
        }
        
        obstacleGrid.at(0).at(0) = 1;
        recursion(obstacleGrid, turn, result, 0, 0);

        return result;  
    }
};
// @lc code=end

