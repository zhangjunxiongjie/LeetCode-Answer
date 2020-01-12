/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:

    // 优化用空间换时间。先找出每个位置左边和右边的最高墙。
    int trap(vector<int>& height) {
        int capacity = 0; // 容量
        
        vector<int> leftwall, rightwall;
        for (int i = 0; i < height.size(); i++)
        {
            leftwall.push_back(0);
            rightwall.push_back(0);
        }
        
        // 一次循环即可得到所有位置的最高墙
        for (int i = 0, j = height.size() - 1; i < height.size(); i++, j--)
        {
            if (i == 0)
            {
                leftwall.at(i) = 0;
            }
            else if (leftwall.at(i - 1) < height.at(i - 1))
            {
                leftwall.at(i) = height.at(i - 1);
            }
            else
            {
                leftwall.at(i) = leftwall.at(i - 1);
            }
            
            if (j == height.size() - 1)
            {
                rightwall.at(j) = 0;
            }
            else if(rightwall.at(j + 1) < height.at(j + 1))
            {
                rightwall.at(j) = height.at(j + 1);
            }
            else
            {
                rightwall.at(j) = rightwall.at(j + 1);
            }
        }
        

        for (int flag = 0; flag < height.size(); flag++)
        {
            // 两堵墙中的矮墙。
            int wall;
            if (rightwall.at(flag) > leftwall.at(flag))
            {
                wall = leftwall.at(flag);
            }
            else
            {
                wall = rightwall.at(flag);
            }

            if (wall > height.at(flag))
            {
                capacity += (wall - height.at(flag)); 
            }
        }
        
        return capacity;
    }

    /* // 每次都要寻找最高墙和最矮墙。
    int trap(vector<int>& height) {
        
        int capacity = 0; // 容量
        int leftwall = 0, rightwall = 0;
        for (int flag = 0; flag < height.size(); flag++)
        {
            
            // 左边最高墙。
            if (flag > 0 && height.at(flag - 1) > height.at(leftwall))
            {
                leftwall = flag - 1;
            }
            
            // 右边最高墙。
            rightwall = flag;
            for (int right = flag + 1; right < height.size(); right++)
            {
                if (height.at(right) > height.at(rightwall))
                {
                    rightwall = right;
                }
            }

            // 两堵墙中的矮墙。
            int wall;
            if (height.at(leftwall) > height.at(rightwall))
            {
                wall = height.at(rightwall);
            }
            else
            {
                wall = height.at(leftwall);
            }

            if (wall > height.at(flag))
            {
                capacity += (wall - height.at(flag)); 
            }
        }
        
        return capacity;
    }
    */
};
// @lc code=end

