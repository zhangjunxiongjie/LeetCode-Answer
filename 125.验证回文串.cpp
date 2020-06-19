/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool is_target_char(char& ch)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            return true;
        }
        else if(('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isPalindrome(string s) {
        
        for (int front = 0, behind = s.size() - 1; front < behind; )
        {
            while (front < behind && !is_target_char(s.at(front)))
            {
                front++;
            }
            while (front < behind && !is_target_char(s.at(behind)))
            {
                behind--;
            }

            if (front < behind && s.at(front) != s.at(behind))
            {
                return false;
            }
            else
            {
                front++;
                behind--;
            }
            
        }
        
        return true;
    }
};
// @lc code=end

