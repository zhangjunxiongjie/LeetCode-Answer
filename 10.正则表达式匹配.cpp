/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool judge_clear(string& p, int pCounter)
    {
        // 判断最后可能出现的字符与 '*' 字符组合
        pCounter = pCounter + 1;
        while (pCounter < p.size() && p.at(pCounter) == '*')
        {
            pCounter += 2;
        }
        if(pCounter != p.size() + 1)
        {
            return false;
        }

        return true;
    }
    void recursion(string& s, string& p, int sCounter, int pCounter, bool& result)
    {
        if ((sCounter >= s.size()) || (pCounter >= p.size()))
        {
            // 两个字符串完全匹配时才能返回 true
            if ((sCounter >= s.size()) && (pCounter >= p.size()))
            {
                result = true;
            }
            else if(pCounter < p.size() && judge_clear(p, pCounter))
            {
                result = true;              
            }
        }
        else if((pCounter + 1 < p.size()) && (p.at(pCounter + 1) == '*'))
        {
            // 匹配零个
            recursion(s, p, sCounter, pCounter + 2, result);
            
            if(p.at(pCounter) != '.')
            {
                // 匹配更多个。
                int i = 0;
                while (!result && (sCounter + i < s.size()) && (s.at(sCounter + i) == p.at(pCounter)))
                {
                    recursion(s, p, sCounter + i + 1, pCounter + 2, result);
                    i++;
                }
            }
            else
            {
                // 匹配更多个。
                int i = 0;
                while (!result && (sCounter + i < s.size()))
                {
                    recursion(s, p, sCounter + i + 1, pCounter + 2, result);
                    i++;
                }
            }

        }
        else
        {
            if (s.at(sCounter) == p.at(pCounter))
            {
                recursion(s, p, sCounter + 1, pCounter + 1, result);
            }
            else if(p.at(pCounter) == '.')
            {
                recursion(s, p, sCounter + 1, pCounter + 1, result);
            }
        }
    }
    bool isMatch(string s, string p) {
        bool result = false;

        // 只能从头开始匹配。两字符串完全匹配时才能返回 true。
        recursion(s, p, 0, 0, result);
        
        return result;
    }
};


// @lc code=end

