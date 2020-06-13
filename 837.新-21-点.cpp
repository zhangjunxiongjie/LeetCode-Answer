/*
 * @lc app=leetcode.cn id=837 lang=cpp
 *
 * [837] 新21点
 */

// @lc code=start
class Solution {
public:
    void recursion(int presentValue, int K, int W, map<int, int>& assistant)
    {
        for (int value = 1; value <= W; value++)
        {
            int sumValue = presentValue + value;
            if (sumValue >= K)
            {
                auto iterMap = assistant.find(sumValue);
                if (iterMap == assistant.end())
                {
                    assistant[sumValue] = 1;
                }
                else
                {
                    iterMap->second++;
                }
            }
            else
            {
                recursion(sumValue, K, W, assistant);
            }
        }
        
    }
    // 又是动态规划状态转移，太难了不会！！！未解答。
    double new21Game(int N, int K, int W) {
        
        // 特殊情况无需抽取
        if (K == 0)
        {
            return 1.0;
        }
        // 辅助字典。
        map<int, int> assistant;

        recursion(0, K, W, assistant);
        int leftN = 0;
        int sum = 0;
        for (auto iterMap = assistant.begin(); iterMap != assistant.end(); ++iterMap)
        {
            if (iterMap->first <= N)
            {
                leftN += iterMap->second;
            }
            
            sum += iterMap->second;

            cout << iterMap->first << ":" << iterMap->second << endl;
        }
        
        return double(leftN) / double(sum);
    }
};
// @lc code=end

