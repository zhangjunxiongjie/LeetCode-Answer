/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    // 耗时较多有待改进。
    // 直接递归进行比较。
    bool recursion(string& s1, string& s2, string& s3, int iter1, int iter2, int iter3) {

        if (iter1 == s1.size() && iter2 == s2.size() && iter3 == s3.size())
        {
            return true;
        }

        for (; iter3 < s3.size(); iter3++)
        {
            if (iter1 == s1.size())
            {
                for (; iter2 < s2.size() && iter3 < s3.size(); iter2++, iter3++)
                {
                    if (s2.at(iter2) != s3.at(iter3))
                    {
                        return false;
                    }
                }
                if (iter2 == s2.size() && iter3 == s3.size())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (iter2 == s2.size())
            {
                for (; iter1 < s1.size() && iter3 < s3.size(); iter1++, iter3++)
                {
                    if (s1.at(iter1) != s3.at(iter3))
                    {
                        return false;
                    }
                }
                if (iter1 == s1.size() && iter3 == s3.size())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            if (s1.at(iter1) == s2.at(iter2) && s2.at(iter2) == s3.at(iter3))
            {
                if (recursion(s1, s2, s3, iter1 + 1, iter2, iter3 + 1) || recursion(s1, s2, s3, iter1, iter2 + 1, iter3 + 1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (s1.at(iter1) == s2.at(iter2) && s2.at(iter2) != s3.at(iter3))
            {
                return false;
            }
            else if (s1.at(iter1) != s2.at(iter2))
            {
                if (s1.at(iter1) == s3.at(iter3))
                {
                    iter1++;
                }
                else if (s2.at(iter2) == s3.at(iter3))
                {
                    iter2++;
                }
                else
                {
                    return false;
                }
            }
        }

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        
        return recursion(s1, s2, s3, 0, 0, 0);
    }

};



// @lc code=end

