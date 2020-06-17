/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        
        // 去空格。
        int p = 0;
        while ((p < str.size()) && (str.at(p) == ' '))
        {
            p++;
        }
        str = str.substr(p, str.size() - p);
        if (str.size() == 0)
        {
            return 0;
        }
        
        bool flag = false; // 正负号标记。
        if (str.at(0) == '-' || str.at(0) == '+')
        {
            if (str.at(0) == '-')
            {
                flag = true;
            }
            str = str.substr(1, str.size() - 1);
        
            if (str.size() == 0)
            {
                return 0;
            }
        }

        if ('0' <= str.at(0) && str.at(0) <= '9')
        {
            // 去头部的零
            int head = 0;
            while ((head < str.size()) && (str.at(head) == '0'))
            {
                head++;
            }
            str = str.substr(head, str.size());

            int i = 0;
            while (i < str.size() && '0' <= str.at(i) && str.at(i) <= '9')
            {
                i++;
            }
            str = str.substr(0, i);

            if (flag == true) // 负数
            {
                string INTMINStr = to_string(INT_MIN);
                INTMINStr = INTMINStr.substr(1, INTMINStr.size()); // 去掉负号。

                if ((str.size() > INTMINStr.size()) || ((str.size() == INTMINStr.size()) && (str > INTMINStr)))
                {
                    return INT_MIN;
                }
                else
                {
                    int j = 0;
                    while (j < i)
                    {
                        // 这里用减号一来是避免溢出（负数比正数多一个），二来可以避免取反运算
                        result = result * 10 - (str.at(j) - 48);
                        j++;
                    }
                }
            }
            else // 正数。
            {
                string INTMAXStr = to_string(INT_MAX);
                if ((str.size() > INTMAXStr.size()) || ((str.size() == INTMAXStr.size()) && (str > INTMAXStr)))
                {
                    return INT_MAX;
                }
                else
                {
                    int j = 0;
                    while (j < i)
                    {
                        result = result * 10 + (str.at(j) - 48);
                        j++;
                    }
                }
            }
        }
        else
        {
            return 0;
        }
        
        return result;
    }
};
// @lc code=end

