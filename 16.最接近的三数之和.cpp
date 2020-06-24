/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int result = nums.at(0) + nums.at(1) + nums.at(2);
        for (int hub = 0; hub < nums.size(); hub++)
        {
            int begin = hub + 1;
            int end = nums.size() - 1;
            while (begin < end)
            {
                int sum = nums.at(hub) + nums.at(begin) + nums.at(end);
                if (abs(sum - target) < abs(result - target))
                {
                    result = sum;
                }

                if (sum > target)
                {
                    end--;
                }
                else if (sum < target)
                {
                    begin++;
                }
                else
                {
                    return result;
                }
            }
        }

        return result;
    }
};
// @lc code=end
