/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    // 时间上还有待优化。
    typedef struct 
    {
        int key;
        int value;
    }node;
    // 合并。
    void merge(vector<node>& buffer,vector<node>::iterator& front, vector<node>::iterator& behind)
    {
        if (behind != buffer.end() && front->key + front->value >= behind->key)
        {
            int cache = behind->value + (behind->key - front->key);
            if (front->value < cache)
            {
                front->value = cache;
            }
            buffer.erase(behind);
            }
    }

    // 使用 vector 实现
    int longestConsecutive(vector<int>& nums){
        int result = 0;
        
        vector<node> buffer;

        for (int i = 0; i < nums.size(); i++)
        {
            auto firstiter = buffer.begin();
            auto iter = buffer.begin();
            for (; iter != buffer.end(); iter++)
            {
                if (nums.at(i) + 1 == iter->key)
                {
                    // 这里绝不会改变顺序。
                    iter->key--;
                    iter->value++;                     
                    
                    if (firstiter != iter) // 避免是第一个iter,合并。
                    {
                        merge(buffer, firstiter, iter);
                    }
                    
                    break;
                }
                else if(iter->key > nums.at(i))
                {
                    break;
                }
                
                if (iter->key <= nums.at(i) && nums.at(i) <= iter->key + iter->value)
                {
                    if (nums.at(i) == iter->key + iter->value)
                    {
                        iter->value++;

                        auto nextiter = iter + 1; // 合并。
                        merge(buffer, iter, nextiter);

                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                firstiter = iter; // 记录上一个 iter
            }
            if (iter == buffer.end()) // 
            {
                buffer.push_back(node{nums.at(i), 1});// 添加到最后。
            }
            else if(iter->key > nums.at(i)) //
            {
                buffer.insert(iter, node{nums.at(i), 1});
            }
        }
        
        for (auto iter = buffer.begin(); iter != buffer.end(); iter++)
        {
            if (iter->value > result)
            {
                result = iter->value;
            }
            
            cout << iter->key << ":" << iter->value <<":";
        }
        
        return result;
    }

};
// @lc code=end

