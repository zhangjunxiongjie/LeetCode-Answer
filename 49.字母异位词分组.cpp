/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
// @lc code=start
class Solution {
public:
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

