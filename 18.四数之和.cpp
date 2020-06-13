/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    typedef struct dot
    {
        int x;
        int y;
        bool operator != (dot const& _A) const
        {
            if ((_A.x != x && _A.x != y) && (_A.y != x && _A.y != y))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }Dot;
    // 时间复杂度和空间复杂度较高。
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        sort(nums.begin(), nums.end());

        map<int, vector<Dot>> buffer; 
        
        // 数组元素个数小于四个无解。
        if (nums.size() < 4)
        {
            return result;
        }

        for (int row = 0; row < nums.size(); row++)
        {
            for (int line = row + 1; line < nums.size(); line++)
            {
                Dot temp;
                temp.x = row;
                temp.y = line;
                int sum = nums.at(row) + nums.at(line);
                
                auto iter = buffer.find(sum);
                if (iter == buffer.end())
                {
                    vector<Dot> cache;
                    cache.push_back(temp);
                    buffer.insert(pair<int, vector<Dot>>(sum, cache));
                }
                else
                {
                    iter->second.push_back(temp);
                }
                
                // 剪枝。
                while (line + 1 < nums.size() && nums.at(line) == nums.at(line + 1))
                {
                    line++;
                }
            }
        }

        auto iterLeft = buffer.begin(); // 正向迭代器。
        auto iterRight = buffer.rbegin(); // 方向迭代器
        set<vector<int>> assistantSet;
        while (iterLeft->first <= iterRight->first)
        {
            if (iterLeft->first + iterRight->first == target)
            {
                for (auto iterDotSmall = iterLeft->second.begin(); iterDotSmall != iterLeft->second.end(); ++iterDotSmall)
                {
                    for (auto iterDotBig = iterRight->second.begin(); iterDotBig != iterRight->second.end(); ++iterDotBig)
                    {
                        if (*iterDotSmall != *iterDotBig)
                        {
                            vector<int> cache;
                            cache.push_back(nums.at(iterDotSmall->x));
                            cache.push_back(nums.at(iterDotSmall->y));
                            cache.push_back(nums.at(iterDotBig->x));
                            cache.push_back(nums.at(iterDotBig->y));
                            
                            // 便于使用集合去重。
                            sort(cache.begin(), cache.end());
                            
                            auto iterSet = assistantSet.find(cache);
                            if (iterSet == assistantSet.end())
                            {
                                assistantSet.insert(cache);
                                result.push_back(cache);
                            }
                        }
                    }
                }
                ++iterLeft;
            }
            else if(iterLeft->first + iterRight->first > target)
            {
                ++iterRight;
            }
            else
            {
                ++iterLeft;
            }

            if (iterLeft == buffer.end() || iterRight == buffer.rend())
            {
                break;
            }
            
        }        
        return result;
    }
    
};
// @lc code=end

