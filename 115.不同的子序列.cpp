/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度较高，超时。未解决。
    void Try(map<char, vector<int>>& assistant, string& t, int& count, int tier, int max){
        if (tier == t.size())
        {
            count++;
        }
        else
        {
            auto mapiter = assistant.find(t.at(tier));
            if (mapiter == assistant.end())
            {
                return ;
            }
            else
            {
                for (int i = mapiter->second.size() - 1; i >= 0; i--)
                {
                    if (mapiter->second.at(i) > max)
                    {
                        Try(assistant, t, count, tier + 1, mapiter->second.at(i));
                    }
                    else
                    {
                        return ;
                    }
                }
            }
        }
    }

    int numDistinct(string s, string t) {
        map<char, vector<int>> assistant;
        for (auto iter = s.begin(); iter != s.end(); iter++)
        {
            int i = 0;
            for (; i < t.size(); i++)
            {
                if (*iter == t.at(i))
                {
                    break;
                }
            }
            if (i == t.size())
            {
                s.erase(iter);
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            auto mapiter = assistant.find(s.at(i));
            if (mapiter == assistant.end())
            {
                assistant.insert(pair<char, vector<int>>(s.at(i), {i}));
            }
            else
            {
                mapiter->second.push_back(i);
            }
        }
        
        int result = 0;
        Try(assistant, t, result, 0, -1);
        return result;
    }
};
// @lc code=end

