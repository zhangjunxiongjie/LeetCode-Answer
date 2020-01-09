/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
// 依次确定每一行的位置放在cache数组中
// 占据的位置放在buffer中，用于快速判断
class Solution {
public:

    // 将每一行皇后的位置转化为字符串信息。
    void create(int n, vector<int>& cache, vector<vector<string>>& result)
    {
        vector<string> buffer1;

        for (int i = 0; i < n; i++)
        {
            string buffer2;

            for (int j = 0; j < cache[i]; j++)
                buffer2 = buffer2 + '.';
            buffer2 = buffer2 + 'Q';
            for (int j = cache[i] + 1; j < n; j++)
                buffer2 = buffer2 + '.';

            buffer1.push_back(buffer2);
        }

        result.push_back(buffer1);
    }

    // 递归尝试所有可能
    void findmay(vector<vector<string>>& result, vector<int>& cache, int n, int now)
    {
        if (n == now)
        {
            create(n, cache, result);

            return;
        }

        vector<int> impose;
        for (int i = 0; i < n; i++)
        {
            impose.push_back(0);
        }

        // 这里的问题是每一层都要重新计算限制条件
        for (int i = 0; i < now; i++) // 计算限制条件
        {
            impose[cache[i]] = 1;
            int impose1 = cache[i] - (now - i);
            int impose2 = cache[i] + (now - i);

            if (impose1 >= 0)
            {
                impose[impose1] = 1;
            }
            if (impose2 < n)
            {
                impose[impose2] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (impose.at(i) == 0)
            {
                cache.at(now) = i; // 
                findmay(result, cache, n, now + 1);
                cache.at(now) = -1; // 还原
            }
        }

    }


    vector<vector<string>> solveNQueens(int n) {
	    vector<vector<string>>& result = *new vector<vector<string>>;

        vector<int> cache;  //记录每一行占据到的位置
        for (int i = 0; i < n; i++)
        {
            cache.push_back(-1);
        }
        
        // 递归实现方法。
        // findmay(result, cache, n, 0); // 从第零行开始
        
        vector<int> impose;
        int now = 0;
        while (now != -1)
        {
            if (n == now)
            {
                create(n, cache, result);
                now--;
            }

            // 依然存在每次都需要计算限制条件的问题！！可优化。
            impose.clear();
            for (int i = 0; i < n; i++)
            {
                impose.push_back(0);
            }
            for (int i = 0; i < now; i++) // 计算限制条件
            {
                impose[cache[i]] = 1;
                int impose1 = cache[i] - (now - i);
                int impose2 = cache[i] + (now - i);

                if (impose1 >= 0)
                {
                    impose[impose1] = 1;
                }
                if (impose2 < n)
                {
                    impose[impose2] = 1;
                }
            }

            int sign = cache.at(now) + 1;
            for (; sign < n; sign++)
            {
                if (impose.at(sign) == 0)
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

