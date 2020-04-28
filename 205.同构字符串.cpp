/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    // 利用映射关系实现字符串匹配。
    bool isIsomorphic(string s, string t){
        
        // 总共可能有 128 种字符,assistant 保存映射关系
        vector<int> assistants(128), assistantt(128); 
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char s_ch = s.at(i);
            char t_ch = t.at(i);
            // 映射关系不相同时
            if (assistants.at(s_ch) != assistantt.at(t_ch))
            {
                return false;
            }
            else
            {
                if (assistants.at(s_ch) == 0) // 建立一个唯一的映射关系
                {
                    assistants.at(s_ch) = count + 1;
                    assistantt.at(t_ch) = count + 1;
                    count++;
                }
            }
        }
        return true;
    }
    /*
    // 利用匹配关系实现字符串匹配。
    bool isIsomorphic(string s, string t) {
        
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if ((s.at(i) == s.at(j)) != (t.at(i) == t.at(j)))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    */
};
// @lc code=end

