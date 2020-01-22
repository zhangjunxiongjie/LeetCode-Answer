/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // 字母大写转小写。
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            // 找到下一个字母或数字
            while (('a' > s.at(i) || s.at(i) > 'z') && ('0' > s.at(i) || s.at(i) > '9'))
            {
                i++;
                if (i >= j)
                {
                    break;
                }
            }
            while (('a' > s.at(j) || s.at(j) > 'z') && ('0' > s.at(j) || s.at(j) > '9'))
            {
                j--;
                if (i >= j)
                {
                    break;
                }
            }
            if (i >= j)
            {
                break;
            }
            else if (s.at(i) != s.at(j))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

