/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
// @lc code=start
class Solution {
public:
    // 另一个做法是先对每一个字符串进行排序然后再进行分类。
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

    /*
    // 优化版。依然超时！！！
    // 判断两个字符串是否为字母异位词。
    bool judge(string& str, vector<int> compare)
    {
        for (int i = 0; i < str.size(); i++)
        {
            // 因为这里要对compare进行修改但是compare后续还要使用所以这里没有使用引用。
            if (compare.at(str.at(i) - 'a') > 0)
                compare.at(str.at(i) - 'a')--; 
            else
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>& result = *new vector<vector<string>>;

        vector<vector<int>> compare;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> cache;
            cache.resize(26, 0); // 26个零
            string& str = strs.at(i);

            for (int j = 0; j < str.size(); j++)
            {
                cache.at(str.at(j) - 'a')++; // 记录每个字幕的个数
            }
            compare.push_back(cache);
        }

        vector<int> sign; // 标志数组
        for (int i = 0; i < strs.size(); i++)
        {
            sign.push_back(i);
        }
        vector<int> seat;
        while (!sign.empty())
        {
            int flag = sign.at(sign.size() - 1);
            string str = strs.at(flag);

            int i = 0;
            for (; i < result.size(); i++)
            {
                if (result.at(i).at(0).size() == str.size() && judge(str, compare.at(seat.at(i))))
                {
                    result.at(i).push_back(str);
                    break;
                }
            }
            if (i == result.size())
            {
                vector<string> buffer;
                buffer.push_back(str);

                seat.push_back(flag);
                result.push_back(buffer);
            }

            sign.pop_back();
        }

        return result;
    }
    */

    /*
    // 超时！！！
    // 判断两个字符串是否为字母异位词。
    bool judge(string& str, vector<int> compare)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if(compare.at(str.at(i) - 'a') > 0)
                compare.at(str.at(i) - 'a')--; // 因为这里要对compare进行修改但是compare后续还要使用所以这里没有使用引用。
            else
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>& result = *new vector<vector<string>>;

        vector<vector<int>> compare;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> cache;
            cache.resize(26, 0); // 26个零
            string& str = strs.at(i);

            for (int j = 0; j < str.size(); j++)
            {
                cache.at(str.at(j) - 'a')++; // 记录每个字幕的个数
            }
            compare.push_back(cache);
        }

        vector<int> sign; // 标志数组
        for (int i = 0; i < strs.size(); i++)
        {
            sign.push_back(i);
        }
        while (!sign.empty())
        {
            int flag = sign.at(sign.size() - 1);
            vector<string> cache;
            cache.push_back(strs.at(flag));
            sign.pop_back(); // 删除最后一个元素。
            for (auto i = sign.begin(); i != sign.end(); i++)
            {
                if (cache.at(0).size() == strs.at(*i).size() && judge(strs.at( *i ), compare.at(flag)))
                {
                    cache.push_back(strs.at( *i ));
                    sign.erase(i);
                    i--;
                }
            }
            result.push_back(cache);
        }
        return result;
    }
    */
    
};
// @lc code=end

