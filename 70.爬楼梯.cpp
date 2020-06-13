/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 牛逼的动态规划。
    int climbStairs(int n) {
        int front = 1;
        int behind = 2;
        if (n == 0)
        {
            return 1;
        }
        else if(n == 1)
        {
            return front;
        }
        else if(n == 2)
        {
            return behind;
        }
        else
        {
            for (int nNow = 2; nNow < n; nNow++)
            {
                int middle = behind;
                behind = front + behind;
                front = middle;
            }
            return behind;
        }
    }
    // int recursion(int n, map<int, int>& assistant)
    // {
    //     // 判断是否包含 key 为 n 的键值对。
    //     if (assistant.count(n) == 0) 
    //     {
    //         assistant[n] = recursion((n - 1), assistant) + recursion((n - 2), assistant);
            
    //     }
    //     return assistant[n];
    // }
    // // 使用额外空间优化计算量。通法。
    // int climbStairs(int n) {
    //     map<int, int> assistant;
    //     assistant[0] = 1;
    //     assistant[1] = 1;
    //     assistant[2] = 2;

    //     return recursion(n, assistant);
    // }
};
// @lc code=end

