/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    bool palindromeJudge(string s)
    {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--)
        {
            if (s.at(left) != s.at(right))
            {
                return false;
            }
        }
        return true;
    }
    // 彻底无语了，靠，时间复杂度和空间复杂度较高。
    string longestPalindrome(string s) {
        string result;
        for (int now = s.size() / 2; now >= 0; now--)
        {
            if (result.size() > (now * 2) || result.size() == s.size())
            {
                break;
            }
            int nowLeftEven = now;
            int nowRightEven = now;

            int nowLeftOdd = now;
            int nowRightOdd = now + 1;
            
            bool signalEven = true;
            bool signalOdd = true;
            while (signalEven || signalOdd)
            {
                int sLenEven = nowRightEven - nowLeftEven;
                if (signalEven && (nowLeftEven - 1 >= 0 && nowRightEven + 1 <= s.size()) && palindromeJudge(s.substr(nowLeftEven - 1, sLenEven + 2)))
                {
                    nowLeftEven--;
                    nowRightEven++;
                    sLenEven += 2;
                }
                else
                {
                    signalEven = false;
                }
                
                int sLenOdd = nowRightOdd - nowLeftOdd;
                if (signalOdd && (nowLeftOdd - 1 >= 0 && nowRightOdd + 1 <= s.size()) && palindromeJudge(s.substr(nowLeftOdd - 1, sLenOdd + 2)))
                {
                    nowLeftOdd--;
                    nowRightOdd++;
                    sLenOdd += 2;
                }
                else
                {
                    signalOdd = false;
                }
                
                if (sLenEven > result.size())
                {
                    result = s.substr(nowLeftEven, sLenEven);
                }
                if (sLenOdd > result.size())
                {
                    result = s.substr(nowLeftOdd, sLenOdd);
                }
                
            }
            
        }
        for (int now = s.size() / 2 + 1; now < s.size(); now++)
        {
            if (result.size() > ((s.size() - now) * 2) || result.size() == s.size())
            {
                break;
            }
            
            int nowLeftEven = now;
            int nowRightEven = now;

            int nowLeftOdd = now;
            int nowRightOdd = now + 1;
            
            bool signalEven = true;
            bool signalOdd = true;
            while (signalEven || signalOdd)
            {
                int sLenEven = nowRightEven - nowLeftEven;
                if (signalEven && (nowLeftEven - 1 >= 0 && nowRightEven + 1 <= s.size()) && palindromeJudge(s.substr(nowLeftEven - 1, sLenEven + 2)))
                {
                    nowLeftEven--;
                    nowRightEven++;
                    sLenEven += 2;
                }
                else
                {
                    signalEven = false;
                }
                
                int sLenOdd = nowRightOdd - nowLeftOdd;
                if (signalOdd && (nowLeftOdd - 1 >= 0 && nowRightOdd + 1 <= s.size()) && palindromeJudge(s.substr(nowLeftOdd - 1, sLenOdd + 2)))
                {
                    nowLeftOdd--;
                    nowRightOdd++;
                    sLenOdd += 2;
                }
                else
                {
                    signalOdd = false;
                }
                
                if (sLenEven > result.size())
                {
                    result = s.substr(nowLeftEven, sLenEven);
                }
                if (sLenOdd > result.size())
                {
                    result = s.substr(nowLeftOdd, sLenOdd);
                }
                
            }
            
        }

        return result;
    }
};
// @lc code=end

