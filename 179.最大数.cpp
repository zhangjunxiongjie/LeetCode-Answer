/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    // 还是有些问题。
    string countTostring(int target){
        string result;
        while (target > 0)
        {
            int place = target % 10;
            result = char(place + 48) + result;
            target /= 10;
        }
        return result;
    }
    bool judge(string a, string b){
        int i = 0;
        for (; i < a.size() && i < b.size(); i++)
        {
            if (a.at(i) < b.at(i))
            {
                return true;
            }
            else if(a.at(i) > b.at(i))
            {
                return false;
            }
        }
        if (i == a.size())
        {
            return false;
        }
        else
        {
            return true;
        }
        
        
    }
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> numsstr;
        for (int i = 0; i < nums.size(); i++)
        {
            string middle = countTostring(nums.at(i));
            // cout << middle << endl;
            numsstr.push_back(middle);
        }
        for (int i = 0; i < numsstr.size(); i++)
        {
            for (int j = i + 1; j < numsstr.size(); j++)
            {
                if (judge(numsstr.at(i), numsstr.at(j)))
                {
                    string middle = numsstr.at(i);
                    numsstr.at(i) = numsstr.at(j);
                    numsstr.at(j) = middle;
                }
            }
        }
        for (int i = 0; i < numsstr.size(); i++)
        {
            result += numsstr.at(i);
        }
        
        return result;
    }
};
// @lc code=end

