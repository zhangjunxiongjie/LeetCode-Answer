/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.size() == 0)
        {
            return result; 
        }
        else
        {
            result = strs.at(0);
        }
        
        for (int i = 1; i < strs.size(); i++)
        {
            string middleResult;
            
            string otherString  = strs.at(i);
            for (int iter = 0; iter < otherString.size() && iter < result.size(); iter++)
            {
                if (otherString.at(iter) != result.at(iter))
                {
                    break;
                }
                else
                {
                    middleResult += result.at(iter);
                }
                
            }

            result = middleResult;
            if(result.size() == 0)
            {
                break;
            }
        }
        
        return result;
    }
};
// @lc code=end

