/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
// @lc code=start
class Solution {
public:
    void stringsort(string& s){
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s.at(i) > s.at(j))
                {
                    char middle = s.at(i);
                    s.at(i) = s.at(j);
                    s.at(j) = middle;
                }
                
            }
            
        }
    }

    // 先对每一个字符串进行排序然后再进行分类。
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>>& result = *new(vector<vector<string>>);

        map<string, int> assistant;
        for (auto iter = strs.begin(); iter != strs.end(); iter++)
        {
            string buffer(*iter);
            stringsort(buffer);
            auto mapiter = assistant.find(buffer);
            if (mapiter != assistant.end())
            {
                vector<string>& veciter = result.at(mapiter->second);
                veciter.push_back(*iter);
            }
            else
            {
                assistant.insert(pair<string, int>(buffer, result.size()));
                vector<string> vec;
                vec.push_back(*iter);
                result.push_back(vec);
            }
        }
        return result;
    }

    /* 可通过。
    // 由每个字符串得到一个唯一个标记然后根据标记给字符串分类。
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>>& result = *new(vector<vector<string>>);

        vector<int> assistant{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101}; // 26个素数分别标记26个字母。

        map<double, vector<string>> element; 
        for (auto iter = strs.begin(); iter != strs.end(); iter++)
        {
            double count = 1;
            for (auto iter1 = iter->begin(); iter1 != iter->end(); iter1++)
            {
                count *= assistant.at(*iter1 - 97);
            }
            
            auto mapiter = element.find(count);
            if (mapiter == element.end())
            {
                vector<string> buffer;
                buffer.push_back(*iter);
                element.insert(pair<double,vector<string>>(count, buffer));
            }
            else
            {
                mapiter->second.push_back(*iter);
            }
        }

        for (auto iter = element.begin(); iter != element.end(); iter++)
        {
            result.push_back(iter->second);
        }
        
        return result;
    }
    */
    
};
// @lc code=end

