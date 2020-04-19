/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */


// 双指针法。提交通过但是时间效率依然不是很好。
// @lc code=start
class Solution {
public:
    // 排序。
    void sortint(vector<int>& nums) {
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            for (auto iter1 = iter + 1; iter1 != nums.end(); iter1++)
            {
                if (*iter > * iter1)
                {
                    int middle = *iter;
                    *iter = *iter1;
                    *iter1 = middle;
                }
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        vector<int> buffer(nums); // 避免nums被改变。
        sortint(buffer); // 排序。

        for (int now = 0; now < buffer.size(); )
        {
            int left = now + 1;
            int right = buffer.size() - 1;
            while(left < right)
            {
                if (-buffer.at(now) == buffer.at(left) + buffer.at(right))
                {
                    // 符合条件。
                    vector<int> cache;
                    cache.push_back(buffer.at(now));
                    cache.push_back(buffer.at(left));
                    cache.push_back(buffer.at(right));
                    
                    result.push_back(cache);

                    // 去重。
                    int cacheleft = buffer.at(left);
                    int cacheright = buffer.at(right);
                    while (left < right && (cacheleft == buffer.at(left) || cacheright == buffer.at(right)))
                    {
                        if (cacheleft == buffer.at(left))
                        {
                            left++;
                        }
                        if (cacheright == buffer.at(right))
                        {
                            right--;
                        }
                        
                    }
                    
                }
                else if(-buffer.at(now) > buffer.at(left) + buffer.at(right))
                {
                    left++; // 双指针移动。
                }
                else if(-buffer.at(now) < buffer.at(left) + buffer.at(right))
                {
                    right--;
                }
            }
            
            // 去重。
            int cachenow = buffer.at(now);
            while (now < buffer.size() && cachenow == buffer.at(now))
            {
                now++;
            }
            
        }
        

        return result;
    }

};
// @lc code=end

