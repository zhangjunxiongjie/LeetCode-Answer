/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    // 递归实现。
    void recursion(vector<vector<int>>& result, vector<int>& buffer, int& n, int nowtier, int& tier)
    {
        if (buffer.size() == tier) // 当前层数等于需要的层数。
        {
            result.push_back(buffer);
            return ;
        }
        
        for (int i = nowtier; i <= n; i++)
        {
            
            if (tier - buffer.size() > n - i + 1) // 如果不足
            {
                break;
            }
            
            buffer.push_back(i);
            recursion(result, buffer, n, i + 1, tier);
            buffer.pop_back();
        }
        
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>& result = *new vector<vector<int>>; 
        
        // 特殊情况。
        if (k == 0)
        {
            vector<int> buffer;
            result.push_back(buffer);
            return result;
        }
        else if (n == 0 || n < k)
        {
            return result;
        }
        else if (n == k)
        {
            vector<int> buffer;
            for (int i = 0; i < n; i++)
            {
                buffer.push_back(i + 1);
            }
            result.push_back(buffer);
            return result;
        }
        
        vector<int> buffer;
        recursion(result, buffer, n, 1, k);

        return result;
    }
};
// @lc code=end

