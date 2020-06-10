/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);

        for (int strBegin = 0, strMiddle = str.size() / 2; strBegin <= strMiddle; strBegin++, strMiddle--)
        {
            if (str.at(strBegin) != str.at(str.size() - strBegin - 1))
            {
                return false;
            }
            if (str.at(strMiddle) != str.at(str.size() - strMiddle - 1))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

