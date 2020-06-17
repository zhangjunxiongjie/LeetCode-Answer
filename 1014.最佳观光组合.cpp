/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
    // 算法牛逼啊，但并不是我自个想出来的！！！
    int maxScoreSightseeingPair(vector<int>& A) {
        int result = 0;
        
        int leftValue = A[0] + 0;
        for (int right = 1; right < A.size(); right++)
        {
            int rightValue = A[right] - right; // 做右值时
            int mayLeftValue = A[right] + right; // 可能的左值

            int sum = leftValue + rightValue;
            if (result < sum)
            {
                result = sum;
            }
            
            if (leftValue < mayLeftValue)
            {
                leftValue = mayLeftValue;
            }
            
        }
        
        return result;
    }
};
// @lc code=end

