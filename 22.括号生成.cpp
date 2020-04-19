/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// 递归解法。
// @lc code=start
class Solution {
public:
    typedef struct bracket
    {
        int left = 0;
        int right = 0;
    }brack;
    
    // 暴力破解递归随机生成。
    void recursion(int n, string str, brack& record, vector<string>& result){

        if (2 * n == str.size()) // 括号生成完成。
        {
            result.push_back(str);
        }
        else
        {
            // 确保生成的括号能够匹配。
            if (record.left + 1 >= record.right && record.left < n) // 限制左括号数量。
            {
                record.left++;
                recursion(n, str + "(", record, result);
                record.left--;
            }

            if (record.left >= record.right + 1)
            {
                record.right++;
                recursion(n, str + ")", record, result);
                record.right--;
            }
            
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result = *new vector<string>;

        brack record; // 记录当前左右括号的数量。
        string buffer;
        recursion(n, buffer, record, result);

        return result;
    }
};
// @lc code=end

