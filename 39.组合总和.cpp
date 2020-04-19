/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// 递归求解。
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
            for (int i = flag; i < buffer.size(); i++)
            {
                cache.push_back(buffer.at(i));
                recursion(target, sum + buffer.at(i), i, result, buffer, cache);
                cache.pop_back();
            }
            
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>& result = *new vector<vector<int>>;

        vector<int> buffer(candidates);
        while (!buffer.empty())
        {
            vector<int> cache; // ?
            
            cache.push_back(buffer.at(buffer.size() - 1));
            recursion(target, buffer.at(buffer.size() - 1), 0, result, buffer, cache);

            buffer.pop_back(); // 
        }
        
        return result;
    }
};
// @lc code=end

