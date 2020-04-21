/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>>& result = *new vector<vector<int>>;
        
        int i = 0;
        while (i < intervals.size() && newInterval.at(0) >= intervals.at(i).at(0)) // 首
        {
            result.push_back(intervals.at(i));
            i++;
        }
        if(i == intervals.size()) // 添加到末尾。
        {
            if(i != 0 && result.size() > 0 && result.at(result.size() - 1).at(1) >= newInterval.at(0))
            {
                if (result.at(result.size() - 1).at(1) < newInterval.at(1))
                {
                    result.at(result.size() - 1).at(1) = newInterval.at(1);
                }
            }
            else
            {
                result.push_back(newInterval);
            }
            
        }
        else 
        {
            if (i == 0 || (intervals.at(i - 1).at(1) >= newInterval.at(0) && intervals.at(i - 1).at(1) < newInterval.at(1)) || (intervals.at(i - 1).at(1) < newInterval.at(0) && intervals.at(i).at(0) <= newInterval.at(1))) // // 插入到首部或者中间位置。
            {              
                int rightflag;  // 合并旗帜。

                if (i == 0) // 插入到首部
                {
                    result.insert(result.begin(), newInterval);

                    rightflag = result.at(0).at(1); 
                }
                else if (intervals.at(i - 1).at(1) >= newInterval.at(0) && intervals.at(i - 1).at(1) < newInterval.at(1)) // 至少左相交。可能右相交
                {
                    result.at(i - 1).at(1) = newInterval.at(1);

                    rightflag = result.at(i - 1).at(1); 
                }
                else if (intervals.at(i - 1).at(1) < newInterval.at(0) && intervals.at(i).at(0) <= newInterval.at(1))   // 至多右相交
                {
                    result.push_back(newInterval);
                    rightflag = newInterval.at(1);
                }
                

                // 插入式合并。
                while (i < intervals.size() && rightflag >= intervals.at(i).at(1)) 
                {
                    i++;
                }
                if (i < intervals.size() && rightflag >= intervals.at(i).at(0))
                {
                    result.at(result.size() - 1).at(1) = intervals.at(i).at(1);
                    i++;
                }
                
            }
            else if(intervals.at(i - 1).at(1) < newInterval.at(0) && intervals.at(i).at(0) > newInterval.at(1))
            {   // 左右不相交
                result.push_back(newInterval);
            }
            
            while (i < intervals.size()) // 尾。
            {
                result.push_back(intervals.at(i));
                i++;
            }
            
        }
        
        return result;
    }
};
// @lc code=end

