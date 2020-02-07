/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    // 有点难度不会啊，靠。
    // 先排序。
    void sortint(vector<int>& nums) {
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            for (auto iter1 = iter + 1; iter1 != nums.end(); iter1++)
            {
                if (*iter > * iter1)
                {
                    int middle = *iter;
                    *iter = *iter1;
                    *iter1 = middle;
                }
            }
        }
    }

    typedef struct
    {
        int small;
        int large;
    }Dot;

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>& result = *new vector<vector<int>>;
        vector<int> buffer(nums);
        sortint(buffer);

        map<int, vector<Dot>> employee;
        for (int i = 0; i < buffer.size(); i++)
        {
            
            for (int j = i + 1; j < buffer.size(); j++)
            {
                int twosum = buffer.at(i) + buffer.at(j);
                auto mapiter = employee.find(twosum);
                Dot dot{ i, j };
                if (mapiter == employee.end())
                {
                    vector<Dot> vecdot;
                    vecdot.push_back(dot);
                    employee.insert(pair<int, vector<Dot>>(twosum, vecdot));
                }
                else
                {
                    mapiter->second.push_back(dot);
                }
            }
        }

        for (int i = 0; buffer.at(i) < 1; i++)
        {
            if (i != 0 && buffer.at(i - 1) == buffer.at(i))
            {
                continue;
            }

            int surplus = 0 - buffer.at(i); // 这里有可能溢出。
            
            auto mapiter = employee.find(surplus);
            if (mapiter != employee.end())
            {
                for (auto iter = mapiter->second.begin(); iter != mapiter->second.end(); iter++)
                {
                    vector<int> vec;
                    if (iter->small > i)
                    {
                        vec.push_back(buffer.at(i));
                        vec.push_back(buffer.at(iter->small));
                        vec.push_back(buffer.at(iter->large));

                        cout << buffer.at(i) << ":" << buffer.at(iter->small) << ":" << buffer.at(iter->large) << endl;
                        result.push_back(vec);
                    }
                }
            }
        }
        return result;
    }

};
// @lc code=end

