/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    // 可以尝试先排序再查找，这个题完全没做出来完全是靠 map 的 find 实现。
    // 重新想一个可行的时间复杂度不高的实现。
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> assistant;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            auto p = assistant.find(*iter);
            if (p == assistant.end())
            {
                assistant.insert(pair<int, int>(*iter, 1));
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

