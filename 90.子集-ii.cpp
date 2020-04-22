/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    // 递归实现，超时，超内存，结果还不准确。
    // 递归改循环未解决，有点问题。
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums.at(min) > nums.at(j))
                {
                    min = j;
                }
            }
            int middle = nums.at(min);
            nums.at(min) = nums.at(i);
            nums.at(i) = middle;
        }
        
        vector<int> buffer;
        result.push_back(buffer);
        for (int i = 0; i < nums.size();)
        {
            buffer.push_back(nums.at(i));
            result.push_back(buffer);

            stack<int> heap;
            heap.push(i + 1);

            while (!heap.empty())
            {
                int flag = heap.top();
                
                if (flag == nums.size())
                {
                    buffer.pop_back();
                    heap.pop();
                }

                for (int j = flag; j < nums.size();)
                {
                    buffer.push_back(nums.at(j));
                    result.push_back(buffer);
                    
                    int save = j + 1;

                    int inlastnum = nums.at(j);
                    while (j < nums.size() && inlastnum == nums.at(j))
                    {
                        j++;
                    }        
                    
                    heap.pop();
                    heap.push(j);
                    heap.push(save);
                }
            }
            
            int outlastnum = nums.at(i);
            while (i < nums.size() && outlastnum == nums.at(i))
            {
                i++;
            }
        }
        
        return result;
    }
};
// @lc code=end

