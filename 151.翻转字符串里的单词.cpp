/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string result;
        
        int flag1 = 0, flag2 = 0;
        while (flag1 < s.size())
        {
            for (; flag1 < s.size(); flag1++)
            {
                if (s.at(flag1) != ' ')
                {
                    break;
                }
            }
            for (flag2 = flag1; flag1 < s.size() && flag2 < s.size(); flag2++)
            {
                if (s.at(flag2) == ' ')
                {
                    if (!result.empty())
                    {
                        result = " " + result;
                    }
                    result = s.substr(flag1, flag2 - flag1) + result;
                    break;
                }
                if (flag2 + 1 == s.size())
                {
                    if (!result.empty())
                    {
                        result = " " + result;
                    }
                    result = s.substr(flag1, flag2 - flag1 + 1) + result;
                }
            }
            flag1 = flag2 + 1;
        }
        
        return result;
    }
};
// @lc code=end

