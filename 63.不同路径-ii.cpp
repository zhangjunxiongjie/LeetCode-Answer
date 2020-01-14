/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    // 一个崭新的思路，到达位置[i,j]的路技数等于达到[i-1,j]加上达到[i,j-1]的路径总数。（前提是只能向右向下）（动态规划）
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int result = 0;
        // 特殊情况
        if (obstacleGrid.empty())
        {
            return 0;
        }
        else if (obstacleGrid.at(0).empty())
        {
            return 1;
        }
        else if (obstacleGrid.at(0).at(0) == 1)
        {
            return 0;
        }
        else if (obstacleGrid.at(obstacleGrid.size() - 1).at(obstacleGrid.at(0).size() - 1) == 1)
        {
            return 0;
        }

        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid.at(0).size(); j++)
            {
                if (obstacleGrid.at(i).at(j))
                {
                    obstacleGrid.at(i).at(j) = -1; // 把所有阻碍标志改为-1；方便计路径数。
                } 
            }
        }

        obstacleGrid.at(0).at(0) = 1; // 到达起始位置的路径数为1。
        for (int i = 1; i < obstacleGrid.at(0).size(); i++)
        {
            if (obstacleGrid.at(0).at(i) != -1)
            {
                obstacleGrid.at(0).at(i) = obstacleGrid.at(0).at(i - 1);
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid.at(i).at(0) != -1)
            {
                obstacleGrid.at(i).at(0) = obstacleGrid.at(i - 1).at(0);
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 1; j < obstacleGrid.at(0).size(); j++)
            {
                if (obstacleGrid.at(i).at(j) != -1)
                {
                    long int buffer1 = obstacleGrid.at(i).at(j - 1);
                    long int buffer2 = obstacleGrid.at(i - 1).at(j);

                    if (obstacleGrid.at(i - 1).at(j) == -1)
                    {
                        obstacleGrid.at(i).at(j) = obstacleGrid.at(i).at(j - 1);
                    }
                    else if (obstacleGrid.at(i).at(j - 1) == -1)
                    {
                        obstacleGrid.at(i).at(j) = obstacleGrid.at(i - 1).at(j);
                    }
                    else if(buffer1 + buffer2 < 2147483647)
                    {
                        obstacleGrid.at(i).at(j) = obstacleGrid.at(i).at(j - 1) + obstacleGrid.at(i - 1).at(j);
                    }
                    else
                    {
                        obstacleGrid.at(i).at(j) = 0;
                    }
                    
                }
            }
        }

        result = obstacleGrid.at(obstacleGrid.size() - 1).at(obstacleGrid.at(0).size() - 1);
        if (result == -1) // 此时终点不可达。
        {
            return 0;
        }

        return result;
    }

};
// @lc code=end

