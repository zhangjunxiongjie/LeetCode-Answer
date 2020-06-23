/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string result;

        char carry = '0'; // 进位
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            char chA = '0';
            char chB = '0';
            if (i >= 0)
            {
                chA = a.at(i);
            }
            if (j >= 0)
            {
                chB = b.at(j);
            }

            char temp = chA + chB - '0' + carry - '0';
            if (temp >= '2')
            {
                temp = temp - '2' + '0';
                carry = '1';
            }
            else
            {
                carry = '0';
            }
            
            result.push_back(temp);
        }
        if (carry != '0')
        {
            result.push_back(carry);
        }
        
        reverse(result.begin(), result.end()); // 字符串反转。

        return result;
    }
};
// @lc code=end

