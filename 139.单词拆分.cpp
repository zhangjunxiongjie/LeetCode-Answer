/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    void recursion_matching(set<string>& wordSet, int begin, string& s, int& maxLength, int& minLength, bool& result, vector<bool>& pruning)
    {
        if (begin == s.size())
        {
            result = true;
            return ;
        }
        
        if (pruning.at(begin))
        {
            for (int i = minLength; ((begin + i) <= s.size()) && (i <= maxLength) && (result == false); i++)
            {
                string temp = s.substr(begin, i);
                // cout << temp << endl;
                auto iter = wordSet.find(temp);
                if (iter != wordSet.end())
                {
                    recursion_matching(wordSet, begin + i, s, maxLength, minLength, result, pruning);
                }
            }
            pruning.at(begin) = false;
        }
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet; 
        int strMaxLength = 0;
        int strMinLength = s.size();
        for (int i = 0; i < wordDict.size(); ++i)
        {   
            // 这里要注意 size 返回无符号整型！！！
            strMaxLength = strMaxLength < wordDict[i].size() ? wordDict[i].size():strMaxLength;

            strMinLength = strMinLength > wordDict[i].size() ? wordDict[i].size():strMinLength;

            wordSet.insert(wordDict[i]);
        }
        bool result = false;
        
        vector<bool> pruning; // 剪枝，对于已经处理过的的起始位置不再处理。
        for (int i = 0; i < s.size(); i++)
        {
            pruning.push_back(true);
        }
        
        recursion_matching(wordSet, 0, s, strMaxLength, strMinLength, result, pruning);

        return result;
    }
};
// @lc code=end

