/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    // 递归实现。 
    void recursion(vector<vector<int>>& result, vector<int>& nums, vector<int>& buffer, vector<int>& impose, int n)
    {
        if (n == nums.size())
        {
            result.push_back(buffer);
            return ;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (impose.at(i)) // 如果未使用
            {
                buffer.push_back(nums.at(i));
                impose.at(i) = 0;
                recursion(result, nums, buffer, impose, n + 1);
                buffer.pop_back();
                impose.at(i) = 1;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>& result = *new vector<vector<int>>;
        
        /*
        // 排序
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums.at(i) > nums.at(j))
                {
                    int middle = nums.at(i);
                    nums.at(i) = nums.at(j);
                    nums.at(j) = middle;
                }
            }
        }
        */
        
        vector<int> buffer, impose;
        for (int i = 0; i < nums.size(); i++)
        {
            impose.push_back(1); // 未使用
        }
        
        recursion(result, nums, buffer, impose, 0);

        return result;
    }
};
// @lc code=end

