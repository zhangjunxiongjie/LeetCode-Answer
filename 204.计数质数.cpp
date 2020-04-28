/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    /*
    // 选出质数，不能通过空间复杂度较高。n * int。
    int countPrimes(int n){
        vector<int> assistant;
        for (int prime = 2; prime < n; prime++)
        {
            if (prime != 2 && prime % 2 == 0)
            {
                continue;
            }
            bool flag = true;
            for (int i = 0; i < assistant.size(); i++)
            {
                if (assistant.at(i) * assistant.at(i) > prime)
                {
                    break;
                }
                if (prime % assistant.at(i) == 0)
                {
                    flag = false;
                }
            }
            if (flag)
            {
                assistant.push_back(prime);
            }
        }
        
        return assistant.size();
    }
    */
    
    // 使用排除法 n * bool。
    int countPrimes(int n) {
        
        int result = 0;
        vector<bool> assistant(n); // 初始化n个值为0的int
        for (int i = 2; i * i < n; i++)
        {
            if (assistant.at(i) == false) 
            {
                for (int j = i * i; j < n; j += i) 
                    assistant.at(j) = true;
            }
        }
        for (int i = 2; i < assistant.size(); i++)
        {
            if (assistant.at(i) == false)
            {
                result++;
            }
        }
        
        return result;
    }
    
};
// @lc code=end

