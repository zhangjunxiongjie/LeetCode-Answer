/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    void recursion(vector<int>& nums, map<int, int>& assist, int& maxLength, int pos, int presentLength)
    {
        if (maxLength == nums.size())
        {
            return ; 
        }
        
        int presentValue = nums.at(pos);
        auto iterMap = assist.find(pos);

        if (iterMap == assist.end())
        {
            for (int i = pos + 1; i < nums.size(); i++)
            {
                if (nums.at(i) > presentValue)
                {
                    recursion(nums, assist, maxLength, i, presentLength + 1);

                    if (i == (pos + 1) && nums.at(i) == (presentValue + 1))
                    {
                        break;
                    }
                    
                }
            }
            
        }
        else
        {
            presentLength += ((iterMap->second) - 1);
        }
        
        if (presentLength > maxLength)
        {
            maxLength = presentLength;
        }
        
    }
    // 时间复杂度和空间复杂度有所优化但还能再优化。
    // 可以使用动态规划。进行倒序求子串最大增序子序列。
    int lengthOfLIS(vector<int>& nums) {
        int length = 0;

        map<int, int> assist;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int tempLength = 0;
            recursion(nums, assist, tempLength, i, 1);
            assist[i] = tempLength;

            if (tempLength > length)
            {
                length = tempLength;
            }
            
        }
        
        return length;
    }

/*
    void recursion(vector<int>& nums, set<int>& assist, int pos, int presentLength, int& maxLength)
    {
        if (maxLength == nums.size())
        {
            return ;
        }
        
        int presentValue = nums.at(pos);

        for (int i = pos + 1; i < nums.size(); i++)
        {
            if (nums.at(i) > presentValue)
            {
                assist.insert(i);
                recursion(nums, assist, i, presentLength + 1, maxLength);

                if (i == pos + 1 && presentValue == (nums.at(i) + 1))
                {
                    break;
                }
                
            }
        }
        if (presentLength > maxLength)
        {
            maxLength = presentLength;
        }
        
    }
    // 时间复杂度和空间复杂度太高了。
    int lengthOfLIS(vector<int>& nums) {
        int length = 0;

        set<int> assist;
        for (int iterVec = 0; iterVec < nums.size(); ++iterVec)
        {
            auto iterSet = assist.find(iterVec);
            if (iterSet == assist.end())
            {
                recursion(nums, assist, iterVec, 1, length);
            }
        }
        
        return length;
    }
*/

};


// @lc code=end

