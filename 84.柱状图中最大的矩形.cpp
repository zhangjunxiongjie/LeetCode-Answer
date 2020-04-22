/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    // 超时！！！
    // 以自己为最低限制找身边的高富帅。
    int largestRectangleArea(vector<int>& heights) {
        
        int max = 0;
        bool allzero = true; // 全为零
        bool allnozero = true; // 全部不为零。
        for (int i = 0; i < heights.size(); i++)
        {
            if (max < heights.at(i))
            {
                max = heights.at(i);
            }
            if (heights.at(i) != 0)
            {
                allzero = false;
            }
            else
            {
                allnozero = false;
            }
            
        }
        if (allzero) // 全为零。
        {
            return 0;
        }
        if (allnozero && max < heights.size())
        {
            max = heights.size();
        }

        int middle = (heights.size() - 1) / 2;
        for (int left = middle, right = middle + 1; left >= 0 && right < heights.size(); left--, right++)
        {
            int buffer[2] = {left, right};
            int count = 1;
            while (count >= 0)
            {
                int i = buffer[count];
                if (heights.at(i) * heights.size() <= max) 
                {
                    count--;
                    continue;
                }
                else
                {
                    int left = i, right = i + 1;
                    while (left - 1 >= 0 && heights.at(left - 1) >= heights.at(i))
                    {
                        left -= 1;
                    }
                    while (right < heights.size() && heights.at(right) >= heights.at(i))
                    {
                        right += 1;
                    }
                    
                    if (max < (right - left) * heights.at(i))
                    {
                        max = (right - left) * heights.at(i);
                    }
                    
                }
                count--;
            }
            
        }

        return max;
    }
};
// @lc code=end

