/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) { 
        string intMaxStr(to_string(INT_MAX));
        string intMinStr(to_string(INT_MIN));
        
        string tempStr(to_string(x));
        
        int left = 0;
        int right = tempStr.size() - 1;
        // 除零。
        while (left < right && tempStr.at(right) == '0')
        {
            right--;
        }
        tempStr = tempStr.substr(left, right - left + 1);
        // 判负
        if (tempStr.at(0) == '-')
        {
            left++;
        }
        // 交换。
        while (left < right)
        {
            char ch = tempStr.at(left);
            tempStr.at(left++) = tempStr.at(right);
            tempStr.at(right--) = ch;
        }
        // 判断是否溢出。
        if ((tempStr.at(0) == '-') && (tempStr.size() == intMinStr.size()) && (tempStr >　intMinStr))
        {
            return 0;
        }
        if((tempStr.at(0) != '-') && (tempStr.size() == intMaxStr.size()) && (tempStr > intMaxStr))
        {
            return 0;
        }
        
        int result = atoi(tempStr.c_str());
        return result;
    }
};
// @lc code=end

