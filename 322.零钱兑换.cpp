/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    void recursion(vector<int>& coins, int& amount, int& number){
        cout << amount << endl;
        for (auto iter = coins.begin(); amount != 0 && iter != coins.end(); ++iter)
        {
            if(*iter == amount)
            {
                number++;
                amount = 0;
            }
            else if (*iter < amount)
            {
                number++;
                amount = amount - *iter;
                
                recursion(coins, amount, number);
                if (amount == 0)
                {
                    break;
                }
                
                amount = amount + *iter;
                number--;
            }
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
        {
            return 0;
        }
        
        int number = 0;
        
        sort(coins.rbegin(), coins.rend());

        recursion(coins, amount, number);

        if (number == 0)
        {
            return -1;
        }
        else
        {
            return number;
        }
        
    }
};
// @lc code=end

