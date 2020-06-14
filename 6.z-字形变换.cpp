/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        // 处理特殊情况。
        if (numRows == 1 ||　numRows == 0)
        {
            return s;
        }
        
        vector<string> middleResult;
        middleResult.resize(numRows);
        
        int n = 0;
        bool sign = true;
        for (auto iterString = s.begin(); iterString != s.end(); ++iterString)
        {
            middleResult.at(n).push_back(*iterString);
            
            // 循环加减。
            if (sign)
            {
                n++;
                if (n == numRows - 1)
                {
                    sign = false;
                }
            }
            else
            {
                n--;
                if (n == 0)
                {
                    sign = true;
                }
            }
            
        }
        
        string result;
        for (auto iterVec = middleResult.begin(); iterVec != middleResult.end(); ++iterVec)
        {
            result += *iterVec;
        }
        
        return result;
    }
};
// @lc code=end

