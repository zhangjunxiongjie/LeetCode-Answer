/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 *
 * [1300] 转变数组后最接近目标值的数组和
 */

// @lc code=start
class Solution {
public:
    typedef struct number
    {
        int valueNumber; // 当前值个数。
        int sum; // 后面数字个数
    }Number;
    // 时间复杂度和空间复杂度较高。有待改进。
    int findBestValue(vector<int>& arr, int target) {
        map<int, Number> assistant;
        
        int minValue = 0;
        int maxValue = 0;
        int maxSum = 0; // 如果 value 可以为负数就没有最小的和。
        for (auto iterVec = arr.begin(); iterVec != arr.end(); ++iterVec)
        {
            auto iterMap = assistant.find(*iterVec);
            if (iterMap == assistant.end())
            {
                Number temp{1, 0};
                assistant[*iterVec] = temp;
            }
            else
            {
                iterMap->second.valueNumber++;
            }
            maxSum += *iterVec;
        }
        minValue = assistant.begin()->first;
        maxValue = assistant.rbegin()->first;
        
        if (target >= maxSum)
        {
            // 目标值大于最大值。
            return maxValue;
        }
        else if(target <= minValue * arr.size())
        {
            
            // 这里有个前提就是除法舍掉小数，而不是四舍五入。
            int divisor = target / arr.size();
            int resultSmallSum = arr.size() * divisor;
            int resultBigSum = arr.size() * (divisor + 1);
            if (abs(target - resultSmallSum) > abs(target - resultBigSum))
            {
                return divisor + 1;
            }
            else
            {
                return divisor;
            }
            
        }
        else  
        {
            int frontSum = 0;
            int frontNumber = 0;
            map<int, Number>::iterator iterLeft;
            map<int, Number>::iterator iterRight;
            for (int valueMove = minValue; valueMove < maxValue; valueMove++)
            {
                auto iterMap = assistant.find(valueMove);
                if (iterMap == assistant.end())
                {
                    Number temp{0, 0};
                    assistant[valueMove] = temp;

                    iterMap = assistant.find(valueMove);
                }
                iterLeft = iterRight;
                iterRight = iterMap;
                
                int sum = frontSum + (iterMap->first) * (arr.size() - frontNumber);
                iterMap->second.sum = sum; 
                if (sum > target)
                {
                    break;
                }
                
                frontSum += iterMap->first * iterMap->second.valueNumber;
                frontNumber += iterMap->second.valueNumber;

            }

            if (abs(target - iterLeft->second.sum) > abs(target - iterRight->second.sum))
            {
                return iterRight->first;
            }
            else
            {
                return iterLeft->first;
            }
            
        }
        
    }
};
// @lc code=end

