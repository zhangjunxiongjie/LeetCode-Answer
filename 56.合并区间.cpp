/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:

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
            // cout << i << endl;

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
                // 得到i位置的标记以便于插入或删除。
                auto iter1 = result.begin();
                for (int j = 0; j < i; iter1++, j++);
                
                // 可省略。
                if (result.at(i - 1).at(1) >= iter->at(0) && result.at(i).at(0) <= iter->at(1)) // 前后均相交。
                {
                    if (result.at(i).at(1) >= iter->at(1))
                    {
                        result.at(i - 1).at(1) = result.at(i).at(1);
                    }
                    else // 
                    {
                        result.at(i - 1).at(1) = iter->at(1);
                    }
                    
                    result.erase(iter1);
                }
                else if (result.at(i - 1).at(1) >= iter->at(0)) // 前面相交。
                {
                    if (result.at(i - 1).at(1) < iter->at(1))
                    {
                        result.at(i - 1).at(1) = iter->at(1);
                    }
                    
                }
                else if(result.at(i).at(0) <= iter->at(1)) //后面相交。 
                {
                    if (iter->at(1) > result.at(i).at(1))
                    {
                        result.at(i).at(1) = iter->at(1);
                    }
                    result.at(i).at(0) = iter->at(0);
                }
                else // 中间不相交
                {
                    result.insert(iter1, *iter);
                }

            }
            
            
            // 向前合并。
            while (i < result.size() && i - 1 >= 0 && result.at(i - 1).at(1) >= result.at(i).at(0))
            {
                if (result.at(i - 1).at(1) < result.at(i).at(1))
                {
                    result.at(i - 1).at(1) = result.at(i).at(1);
                }  
                
                auto iter1 = result.begin();
                for (int j = 0; j < i; iter1++, j++);
                result.erase(iter1);
            }
            // 向后合并。
            while (i + 1 < result.size() && i >= 0 && result.at(i).at(1) >= result.at(i + 1).at(0))
            {
                if (result.at(i).at(1) < result.at(i + 1).at(1))
                {
                    result.at(i).at(1) = result.at(i + 1).at(1);
                }  
                
                auto iter1 = result.begin();
                for (int j = 0; j < i + 1; iter1++, j++);
                result.erase(iter1);
            }

        }
        
        // 可以很好的降低时间复杂度。减少排序的时间。
        return result; // 完全的插入式
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

