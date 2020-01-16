/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>& result = *new vector<int>;
        
        // 2 的 n 次幂，n 位的编码能够表示的数字个数。
        int size = 1 << n; 
        for(int number = 0; number < size; number++){
            // 某一个数字产生格雷编码的方法。
            // 其自身与自身的一半进行异或。
            int graycode = number ^ (number >> 1); 
            result.push_back(graycode);
        }

        return result;
    }
};
// @lc code=end

