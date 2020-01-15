/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    // 递归实现。
    // result 结果存放容器，buffer 临时存放容器，nowtier 当前层，tier 总层，iter 当前指针位置。
    void recursion(vector<vector<int>>& result, vector<int>& nums, vector<int>& buffer, int nowtier, int tier, int iter)
    {
        if (nowtier == tier)
        {
            result.push_back(buffer);
            return ;
        }
        
        for (int i = iter; i < nums.size(); i++)
        {
            if (nums.size() - i + 1 < tier - nowtier)
            {
                return;
            }
            
            buffer.push_back(nums.at(i));
            recursion(result, nums, buffer, nowtier + 1, tier, i + 1);
            buffer.pop_back();
        }

        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>& result = *new vector<vector<int>>;

        vector<int> buffer;
        for (int i = 0; i <= nums.size(); i++)
        {
            recursion(result, nums, buffer, 0, i, 0);
        }

        return result;
    }
};
// @lc code=end

