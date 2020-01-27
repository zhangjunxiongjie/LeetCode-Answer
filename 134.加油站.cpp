/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    // 判断是否能够绕行一周。
    bool detour(vector<int>& gas, vector<int>& cost, int start){
        bool flag = true;
        int gasoline = 0;
        for (int begin = start; begin != start || flag; begin++)
        {
            gasoline += gas.at(begin) - cost.at(begin);
            if (gasoline < 0)
            {
                return false;
            }

            if (begin + 1 == gas.size() && flag)
            {
                flag = false;
                begin = -1; // 循环结束还要加一。
            }
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result = -1;
        for (int i = 0; i < gas.size(); i++)
        {
            if (gas.at(i) >= cost.at(i) && detour(gas, cost, i))
            {
                result = i;
                break;
            }
        }
        return result;
    }
};
// @lc code=end

