/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    typedef struct 
    {
        int x;
        int y;
    }seat;
    
    // 广度优化。标记出所有保留的 "O";
    void findRoad(seat place,vector<vector<char>>& board){
        queue<seat> list;
        if (board.at(place.y).at(place.x) == 'O')
        {
            board.at(place.y).at(place.x) = 'Z'; // 标记。
            list.push(place);
        }
        vector<seat> turn = {{1, 0},{0, 1},{-1, 0},{0, -1}};
        while (!list.empty())
        {   
            for (int i = 0; i < turn.size(); i++)
            {
                seat buffer;
                buffer.x = list.front().x + turn.at(i).x;
                buffer.y = list.front().y + turn.at(i).y;
                
                if (buffer.x >= 0 && buffer.x < board.at(0).size() && buffer.y >= 0 && buffer.y < board.size() && board.at(buffer.y).at(buffer.x) == 'O')
                {
                    board.at(buffer.y).at(buffer.x) = 'Z'; // 标记。
                    list.push(buffer);
                }
            }
            list.pop();
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board.at(0).size() == 0)
        {
            return ;
        }
        
        for (int i = 0; i < board.at(0).size(); i++)
        {
            seat place;
            place.x = i;

            place.y = 0;
            findRoad(place, board); // 第一排
            place.y = board.size() - 1;
            findRoad(place, board); // 最后一排
        }
        for (int i = 1; i < board.size() - 1; i++)
        {
            seat place;
            place.y = i;

            place.x = 0;
            findRoad(place, board); // 第一列
            place.x = board.at(0).size() - 1;
            findRoad(place, board); // 最后一列
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.at(0).size(); j++)
            {
                if (board.at(i).at(j) == 'Z')
                {
                    board.at(i).at(j) = 'O';
                }
                else
                {
                    board.at(i).at(j) = 'X';
                }
            }
        }
    }
};
// @lc code=end

