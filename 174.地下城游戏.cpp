/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    // 逆向动态规划。未解决。
    void recursion(vector<vector<int>>& dungeon, vector<int>& result,int buffer, int min, int x, int y){
        
        buffer = buffer + dungeon.at(x).at(y);
        if (buffer < min)
        {
            min = buffer;
        }
        
        if ((x + 1 < dungeon.size()) || (y + 1 < dungeon.at(0).size()))
        {
            if (x + 1 < dungeon.size())
            {
                recursion(dungeon, result, buffer, min, x + 1, y);
            }
            if (y + 1 < dungeon.at(0).size())
            {
                recursion(dungeon, result, buffer, min, x, y + 1);
            }
        }
        else
        {
            result.push_back(min);
        }
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<int> result;
        
        int buffer = 0;
        int min = 0;
        recursion(dungeon, result, buffer, min, 0, 0);
        
        int max = result.at(0);
        for (int i = 0; i < result.size(); i++)
        {
            if (max < result.at(i))
            {
                max = result.at(i);
            }
        }
        
        return 1 - max; 
    }
};
// @lc code=end

