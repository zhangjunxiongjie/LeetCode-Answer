/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度较差。
    int candy(vector<int>& ratings) {
        int result = 0;
        if (ratings.size() == 0)
        {
            return 0;
        }
        else if (ratings.size() == 1)
        {
            return 1;
        }

        int buffer[ratings.size()];
        for (int i = 0; i < ratings.size(); i++)
        {
            buffer[i] = 0;
        }
        
        if(ratings.at(0) <= ratings.at(1))
        {
            buffer[0] = 1;
        }
        if(ratings.at(ratings.size() - 1) <= ratings.at(ratings.size() - 2))
        {
            buffer[ratings.size() - 1] = 1;
        }

        for (int i = 1; i < ratings.size() - 1; i++)
        {
            if (ratings.at(i - 1) >= ratings.at(i) && ratings.at(i) <= ratings.at(i + 1))
            {
                buffer[i] = 1;
            }
        }
        
        for (int i = 0; i < ratings.size(); i++)
        {
            if (buffer[i] == 1)
            {
                int tier = 1;
                int x = i;
                while (0 <= x - 1 && ratings.at(x - 1) > ratings.at(x))
                {
                    tier++;
                    if (buffer[x - 1] < tier)
                    {
                        buffer[x - 1] = tier;
                    }
                    x--;
                }
                tier = 1;
                x = i;
                while (x + 1 < ratings.size() && ratings.at(x + 1) > ratings.at(x))
                {
                    tier++;
                    if (buffer[x + 1] < tier)
                    {
                        buffer[x + 1] = tier;
                    }
                    x++;
                }
            }
        }
        
        for (int i = 0; i < ratings.size(); i++)
        {
            result += buffer[i];
        }
        
        return result;
    }
};
// @lc code=end

