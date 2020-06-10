/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口解法。
    int lengthOfLongestSubstring(string s) {
        int strLeft = 0, strRight = 0;
        int maxLength = 0;
        
        while (strRight < s.size())
        {
            bool flag = false;
            
            int location = strLeft;
            for (; location < strRight; location++)
            {
                if (s.at(location) == s.at(strRight))
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag)
            {
                strLeft = location + 1;
            }
            else
            {
                if (strRight - strLeft + 1 > maxLength)
                {
                    maxLength = strRight - strLeft + 1;
                }
            }
            
            strRight++;            
        }
        return maxLength;
    }
};
// @lc code=end

