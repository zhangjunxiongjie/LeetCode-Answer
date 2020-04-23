/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    void recursion(vector<string>& result, string& s, string& buffer, int num, int n){
        if (num == 0)
        {
            if(s.size() - n > 1 && s.at(n) == '0')
            {
                return ;
            }
            else if(0 < s.size() - n && s.size() - n <= 3)
            {
                int ch = 0;
                for (int j = n; j < s.size(); j++)
                {
                    ch = ch * 10 + (s.at(j) - 48);
                }
                if (0 <= ch && ch <= 255)
                {
                    for (int j = n; j < s.size(); j++)
                    {
                        buffer += s.at(j);
                    }
                    
                    result.push_back(buffer);
                    
                    for (int j = n; j < s.size(); j++)
                    {
                        buffer.pop_back();
                    }
                }
            }
            
            return ;
        }
        else if(n >= s.size())
        {
            return;
        }
        
        if (s.at(n) == '0')
        {
            buffer += s.at(n);
            buffer += ".";
            
            recursion(result, s, buffer, num - 1, n + 1);
            
            buffer.pop_back();
            buffer.pop_back();

            return ;
        }

        for (int i = n; i < s.size() && i - n < 3; i++)
        {
            int ch = 0;
            for (int j = n; j <= i; j++)
            {
                ch = ch * 10 + (s.at(j) - 48);
                buffer += s.at(j);
            }
            if (0 < ch && ch <= 255)
            {
                buffer += ".";
                recursion(result, s, buffer, num - 1, i + 1);
                buffer.pop_back();
            }
            for (int j = n; j <= i; j++)
            {
                buffer.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>& result = *new vector<string>;
        string buffer;

        if (s.size() >= 4)
        {
            recursion(result, s, buffer, 3, 0);
        }
        
        return result;
    }
};
// @lc code=end

