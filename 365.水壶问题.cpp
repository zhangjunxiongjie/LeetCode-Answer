/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
public:
    void recursion(set<int>& assist, int z, bool& result)
    {
        for (auto iterSet = assist.begin(); result == false && iterSet != assist.end(); ++iterSet)
        {
            if (*iterSet < z)
            {
                recursion(assist, z - *iterSet, result);
            }
            else if(*iterSet == z)
            {
                result = true;
            }
        }
    }
    // 靠，太他妈难了！！！
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0 || z == x || z == y || (x + y) == z)
        {
            return true;
        }
        else if(x == 0 || y == 0)
        {
            return false;
        }
        else if(x + y < z)
        {
            return false;
        }
        
        set<int> assistSet{x, y};
        for (auto iterSet = assistSet.begin(); iterSet != assistSet.end(); ++iterSet)
        {
            auto iter = iterSet;
            ++iter;
            for (; iter != assistSet.end(); ++iter)
            {
                int temp = abs(*iterSet - *iter);
                cout << temp << endl;
                if (temp != 0)
                {
                    // 去重。
                    assistSet.insert(temp);
                    if (temp == z)
                    {
                        return true;
                    }
                }
            }
        }
        
        bool result = false;
        // recursion(assistSet, z, result);
        
        return result;
    }
};
// @lc code=end

