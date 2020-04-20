/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    
    // 合并式解法，超时！对区间排序的原因。
    vector<vector<int>> merger(vector<vector<int>>& intervals) {
        // 按照左区间进行排序。
        for (int i = 0; i < intervals.size(); i++)
        {
            int min = i;
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals.at(min).at(0) > intervals.at(j).at(0))
                {
                    min = j;
                }
                
            }
            int middle = intervals.at(min).at(0);
            intervals.at(min).at(0) = intervals.at(i).at(0);
            intervals.at(i).at(0) = middle;
            
            middle = intervals.at(min).at(1);
            intervals.at(min).at(1) = intervals.at(i).at(1);
            intervals.at(i).at(1) = middle; 
            
        }
        

        for (auto iter = intervals.begin(); iter != intervals.end(); )
        {
            auto iterend = iter + 1; 
            if (iterend == intervals.end())
            {
                break;
            }
            else if (iter->at(1) < iterend->at(0))
            {
                iter = iterend;
            }
            else if(iter->at(1) >= iterend->at(0))
            {
                if(iter->at(1) < iterend->at(1))
                {
                    iter->at(1) = iterend->at(1);
                }
                intervals.erase(iterend);
            }
        }
        return intervals;
    }

    // 插入式解法。不排序。
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        for (auto iter = intervals.begin(); iter != intervals.end(); iter++)
        {
            int i = 0;
            while (i < result.size() && iter->at(0) >= result.at(i).at(0))
            {
                i++;
            }

            if (i == result.size()) // 尾
            {
                result.push_back(*iter);
            }
            else if(i == 0) // 首
            {
                
                if (result.at(i).at(0) > iter->at(1))
                {
                    result.insert(result.begin(), *iter);
                }
                else
                {
                    if (result.at(i).at(1) < iter->at(1))
                    {
                        result.at(i).at(1) = iter->at(1);
                    }
                    result.at(i).at(0) = iter->at(0);
                }
                
            }
            else // 中间
            {
                if (result.at(i - 1).at(1) >= iter->at(0)) // 前面。
                {
                    if (result.at(i - 1).at(1) < iter->at(1))
                    {
                        result.at(i - 1).at(1) = iter->at(1);
                    }
                    
                }
                else if(result.at(i).at(0) <= iter->at(1)) //后面 
                {
                    if (iter->at(1) > result.at(i).at(1))
                    {
                        result.at(i).at(1) = iter->at(1);
                    }
                    result.at(i).at(0) = iter->at(0);
                }
                else
                {
                    auto iter1 = result.begin();
                    for (int j = 0; j < i; iter1++, j++);
                    
                    result.insert(iter1, *iter);
                }
            }
            
        }
        
        // 可以很好的降低时间复杂度。减少排序的时间。
        return merger(result); // 完全的插入式加合并式
    }


    /*
    // 插入式解法。排序始终耗费太多时间。
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        // 按照左区间进行排序。
        for (int i = 0; i < intervals.size(); i++)
        {
            int min = i;
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals.at(min).at(0) > intervals.at(j).at(0))
                {
                    min = j;
                }
                
            }
            int middle = intervals.at(min).at(0);
            intervals.at(min).at(0) = intervals.at(i).at(0);
            intervals.at(i).at(0) = middle;
            
            middle = intervals.at(min).at(1);
            intervals.at(min).at(1) = intervals.at(i).at(1);
            intervals.at(i).at(1) = middle; 
            
        }
        
        for (auto iter = intervals.begin(); iter != intervals.end(); iter++)
        {
            if (result.empty() || iter->at(0) > result.at(result.size() - 1).at(1))
            {
                result.push_back(*iter);
            }
            else
            {
                if (iter->at(1) > result.at(result.size() - 1).at(1))
                {
                    result.at(result.size() - 1).at(1) = iter->at(1);
                }
            }
        }
        
        return result;
    }
    */

    /*
    // 合并式解法，超时！
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按照左区间进行排序。
        for (int i = 0; i < intervals.size(); i++)
        {
            int min = i;
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals.at(min).at(0) > intervals.at(j).at(0))
                {
                    min = j;
                }
                
            }
            int middle = intervals.at(min).at(0);
            intervals.at(min).at(0) = intervals.at(i).at(0);
            intervals.at(i).at(0) = middle;
            
            middle = intervals.at(min).at(1);
            intervals.at(min).at(1) = intervals.at(i).at(1);
            intervals.at(i).at(1) = middle; 
            
        }
        

        for (auto iter = intervals.begin(); iter != intervals.end(); )
        {
            auto iterend = iter + 1; 
            if (iterend == intervals.end())
            {
                break;
            }
            else if (iter->at(1) < iterend->at(0))
            {
                iter = iterend;
            }
            else if(iter->at(1) >= iterend->at(0))
            {
                if(iter->at(1) < iterend->at(1))
                {
                    iter->at(1) = iterend->at(1);
                }
                intervals.erase(iterend);
            }
        }
        return intervals;
    }
    */
};
// @lc code=end

