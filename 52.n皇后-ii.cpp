/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    bool judge(vector<int>& cache, int n, int may)
    {
        for (size_t i = 0; i < n; i++)
        {
            int impose1 = cache[i] - (n - i);
            int impose2 = cache[i] + (n - i);
            if (cache[i] == may || impose1 == may || impose2 == may)
            {
                return false;
            }            
        }
        return true;
    }

    int totalNQueens(int n) {
        int result = 0;
        vector<int> cache;  //记录每一行占据到的位置
        for (int i = 0; i < n; i++)
        {
            cache.push_back(-1);
        }
        vector<int> impose;
        int now = 0;
        while (now != -1)
        {
            if (n == now)
            {
                result++;
                now--;
            }
            int sign = cache.at(now) + 1;
            for (; sign < n; sign++)
            {
                if (judge(cache, now, sign))
                {
                    cache.at(now) = sign;
                    now++;
                    break;
                }
            }
            if (sign == n)
            {
                cache.at(now) = -1;
                now--;
            }
        }
        return result;
    }
};
// @lc code=end

