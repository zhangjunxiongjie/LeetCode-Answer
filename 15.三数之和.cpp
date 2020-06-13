/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */


// 双指针法。提交通过但是时间效率依然不是很好。
// @lc code=start
class Solution {
public:
    // 空间复杂度和时间复杂度依然很高。
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        vector<int> buffer(nums); // 避免nums被改变。
        sort(buffer.begin(), buffer.end()); // 排序。
        
        // 数组元素个数小于三个或者整个数组都大于零。无解。
        if (buffer.size() < 3)
        {
            return result;
        }
        else if (buffer.at(0) > 0)
        {
            return result;
        }

        // now 后面至少要有两个元素才有继续下去的必要。
        for (int now = 0; now < buffer.size() - 2; )
        {
            // now 作为最左值如果大于零则无解。
            if (buffer.at(now) > 0)
            {
                now++;
                continue;
            }
            
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

