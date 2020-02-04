/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    int chartonumber(char c){
        switch (c)
        {
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default:
            return 2;
        }
    }
    // 可以尝试，递归改循环。减少内存使用。
    void createstring(vector<string>& result, vector<string>& assistant, string& digits, string& buffer, int tier){
        if (tier == digits.size())
        {
            result.push_back(buffer);
            return ;
        }
        else
        {
            int mark = chartonumber(digits.at(tier)) - 2; // 
            for (int i = 0; i < assistant.at(mark).size(); i++)
            {
                buffer += assistant.at(mark).at(i);
                
                createstring(result, assistant, digits, buffer, tier + 1);
                
                buffer.erase(buffer.size() - 1);
            }
            
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>& result = *new (vector<string>);
        
        if (digits.size() == 0)
        {
            return result;
        }
        
        vector<string> assistant;
        assistant.push_back("abc"); // 2
        assistant.push_back("def"); // 3
        assistant.push_back("ghi"); // 4
        assistant.push_back("jkl"); // 5
        assistant.push_back("mno"); // 6
        assistant.push_back("pqrs"); // 7
        assistant.push_back("tuv"); // 8
        assistant.push_back("wxyz"); // 9

        string buffer;
        createstring(result, assistant, digits, buffer, 0);
        
        return result;
    }
};
// @lc code=end

