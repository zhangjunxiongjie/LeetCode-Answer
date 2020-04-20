/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:

    void recursion(int& target, int sum, int flag, vector<vector<int>>& result, vector<int>& buffer, vector<int>& cache){

        if (sum == target)
        {
            result.push_back(cache);
        }
        else if(sum > target)
        {    
            return ;
        }
        else
        {
            for (int i = flag; i < buffer.size(); )
            {
                cache.push_back(buffer.at(i));

                recursion(target, sum + buffer.at(i), i + 1, result, buffer, cache);
                cache.pop_back();

                int j = i + 1; // 这里也是为了去重。
                while (j < buffer.size() && buffer.at(i) == buffer.at(j))
                {
                    j++;
                }
                i = j;
            }
            
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>& result = *new vector<vector<int>>;

        vector<int> buffer(candidates);
        // 为了去重进行排序。
        for (int i = 0; i < buffer.size(); i++)
        {
            int min = i;
            for (int j = i + 1; j < buffer.size(); j++)
            {
                if (buffer.at(min) > buffer.at(j))
                {
                    min = j;
                }
                
            }
            int middle = buffer.at(i);
            buffer.at(i) = buffer.at(min);
            buffer.at(min) = middle;
        }

        int lastsum = -1;
        while (!buffer.empty())
        {
            vector<int> cache; // ?
            
            if (buffer.at(0) == lastsum) // 去重。
            {
                buffer.erase(buffer.begin());
                continue;
            }
            
            int sum = buffer.at(0);
            cache.push_back(sum);
            buffer.erase(buffer.begin()); // 

            recursion(target, sum, 0, result, buffer, cache);
            lastsum = sum;
        }
        
        return result;
    }
};
// @lc code=end

