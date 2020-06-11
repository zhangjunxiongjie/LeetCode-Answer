/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>& result = *new vector<int>;
        
        result.resize(T.size());
        
        int max = 30;
        
        for(int nowP = T.size() - 1; nowP >= 0; nowP--)
        {   
            result.at(nowP) = 0;
            if (T.at(nowP) >= max)
            {
                max = T.at(nowP);
                continue;
            }
            
            for (int i = nowP + 1; i < T.size(); )
            {
                if (T.at(nowP) < T.at(i))
                {
                    result.at(nowP) = i - nowP;
                    break;
                }
                else if(result.at(i) != 0)
                {
                    i = i + result.at(i);
                    continue;
                }
                i++; // 配合continue使用，如果放在for括号里就会每次都执行。
            }
            
        }

        return result;
    }
};
// @lc code=end

