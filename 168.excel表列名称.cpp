/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n > 26)
        {
            int consult = 1;
            while (n - consult * 26 > 26)
            {
                consult++;
            }
            
            int remainder = n - consult * 26;
            s = char(remainder + 64) + s;
            n = consult;
        }
        
        s = char(n + 64) + s;
        return s;
    }
};
// @lc code=end

