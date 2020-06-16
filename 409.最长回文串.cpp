/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int maxLength = 0;
        vector<int> assist(58);
        for (auto iterStr = s.begin(); iterStr != s.end(); ++iterStr)
        {
            assist.at(int(*iterStr) - 65)++;
        }

        bool flag = false;
        for (int i = 0; i < assist.size(); i++)
        {
            if (assist.at(i) % 2 == 0)
            {
                maxLength += assist.at(i);
            }
            else
            {
                // 这里不能用 assist.at(i) - 1 因为 assist.at(i)可能是 0。
                maxLength += assist.at(i) / 2 * 2 ;
                flag = true;
            }
        }
        
        if (flag == true)
        {
            maxLength += 1;
        }
        
        return maxLength;
    }
};
// @lc code=end

