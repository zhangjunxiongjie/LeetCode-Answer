/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:

    // 双指针紧缩。时间复杂度较高，有待优化。
    bool judge(map<char, int>& buffer) // 判断可行性。
    {
        for (auto iter = buffer.begin(); iter != buffer.end(); iter++)
        {
            if (iter->second > 0)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        map<char, int> buffer;

        for (int i = 0; i < t.size(); i++)
        {
            auto iter = buffer.find(t.at(i));
            if (iter == buffer.end())
            {
                buffer.insert(pair<char, int>(t.at(i), 1));
            }
            else
            {
                iter->second++;
            }
            
        }
        
        string result = "";
        int resultsize = INT_MAX;
        int minleft = 0, minright = 0;
        int left = 0, right = 0;
        
        while (right < s.size())
        {
            while (right < s.size() && !judge(buffer))
            {
                auto iter = buffer.find(s.at(right));
                while (iter == buffer.end()) // 时间优化。
                {
                    right++;

                    if (right >= s.size())
                    {
                        break;
                    }
                    
                    iter = buffer.find(s.at(right));
                }
                if (right >= s.size())
                {
                    break;
                }

                iter->second--; // 包括left，不包括right；
                right++;
            }
            
            while (judge(buffer))
            {
                if (right - left < resultsize)
                {
                    resultsize = right - left;
                    minleft = left;
                    minright = right;
                }

                auto iter = buffer.find(s.at(left));
                
                // 这里不能优化因为上面要记录。所以必须步进
                if(iter != buffer.end())
                    iter->second++;
                
                left++;
            }
        }
        
        for (int i = minleft; i < minright; i++)
        {
            result += s.at(i);
        }
        
        return result;
    }
};
// @lc code=end

