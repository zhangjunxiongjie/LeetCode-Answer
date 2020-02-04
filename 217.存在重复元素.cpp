/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    // 利用哈希的思想，将元素根据基值分为100堆，可以高效地进行查找。
    // 时间复杂度依然很高。
    bool containsDuplicate(vector<int>& nums){
        map<int, vector<int>> assistant; // 建立基值哈希表。
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            int basecount = (*iter) % 100; // 取基值。 
            auto mapiter = assistant.find(basecount);
            if (mapiter == assistant.end()) // 未找到 
            {
                vector<int> buffer;
                buffer.push_back(*iter);

                assistant.insert(map<int, vector<int>>::value_type(basecount, buffer));
            }
            else // 如果找到了。
            {
                for (auto vectoriter = mapiter->second.begin(); vectoriter != mapiter->second.end(); vectoriter++)
                {
                    if (*iter == *vectoriter)
                    {
                        return true;
                    }
                }
                mapiter->second.push_back(*iter);
            }
        }

        return false;
    }

};
// @lc code=end

