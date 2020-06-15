/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        bool result = true;
        
        // 总共 26 个 小写字母。sameVec 用于存储相同集合。
        vector<bitset<26>> sameVec; 

        vector<vector<string>::iterator> differentVec;

        for (auto iterVec = equations.begin(); result == true && iterVec != equations.end(); ++iterVec)
        {
            if (iterVec->at(0) == iterVec->at(3))
            {
                if (iterVec->at(1) == '=')
                {
                    result = true;
                }
                else
                {
                    result = false;
                }
                
            }
            else if (iterVec->at(1) == '=')
            {
                int x = iterVec->at(0) - 97;
                int y = iterVec->at(3) - 97;

                auto iterX = sameVec.end();
                auto iterY = sameVec.end();
                for (auto iterBit = sameVec.begin(); iterBit != sameVec.end(); ++iterBit)
                {
                    if ((*iterBit)[x] == 1)
                    {
                        iterX = iterBit;
                    }
                    if ((*iterBit)[y] == 1)
                    {
                        iterY = iterBit;
                    }
                }
                
                // 初始化相等集合。
                if (iterX == sameVec.end() && iterY == sameVec.end())
                {
                    bitset<26> tempBit;
                    tempBit[x] = 1;
                    tempBit[y] = 1;
                    sameVec.push_back(tempBit);
                }
                else if(iterX == sameVec.end()) // 相等集合扩展
                {
                    (*iterY)[x] = 1; 
                }
                else if(iterY == sameVec.end()) // 相等集合扩展
                {
                    (*iterX)[y] = 1;
                }
                else
                {
                    // 两个相等集合的合并。如果是同一个集合则不用做任何处理。
                    if (iterX != iterY)
                    {
                        (*iterX) = (*iterX) | (*iterY);
                        sameVec.erase(iterY);
                    }
                    
                }
            }
            else if (iterVec->at(1) == '!')
            {
                differentVec.push_back(iterVec);
            }
        }

        for(auto iterVec = differentVec.begin(); iterVec != differentVec.end(); ++iterVec)
        {
            int x = (*iterVec)->at(0) - 97;
            int y = (*iterVec)->at(3) - 97;

            auto iterX = sameVec.end();
            auto iterY = sameVec.end();
            for (auto iterBit = sameVec.begin(); iterBit != sameVec.end(); ++iterBit)
            {
                if ((*iterBit)[x] == 1)
                {
                    iterX = iterBit;
                }
                if ((*iterBit)[y] == 1)
                {
                    iterY = iterBit;
                }
            }

            if (iterX == iterY && iterX != sameVec.end())
            {
                result = false;
            }
            
        }
        
        return result;
    }

/*
    // 问题的关键在于使用等式固定两个变量之间的关系，没有等式固定关系的变量间可以是任何关系，用不等式判断两个变量不存在固定关系。。
    bool equationsPossible(vector<string>& equations) {
        bool result = true;

        map<char, int> sameSet;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            sameSet[ch] = -1; // 变量默认值为 -1 表示未初始化。
        }
        
        vector<vector<string>::iterator> differentVec;

        int charNumber = 0; // 变量值
        // 将等式两边的变量值设为相同值。
        for (auto iterVec = equations.begin(); result == true && iterVec != equations.end(); ++iterVec)
        {
            if (iterVec->at(0) == iterVec->at(3))
            {
                if (iterVec->at(1) == '=')
                {
                    result = true;
                }
                else
                {
                    result = false;
                }
                
            }
            else if (iterVec->at(1) == '=')
            {
                auto iterX = sameSet.find(iterVec->at(0));
                auto iterY = sameSet.find(iterVec->at(3));
                // 初始化相等集合。
                if (iterX->second == -1 && iterY->second == -1)
                {
                    iterX->second = charNumber;
                    iterY->second = iterX->second;
                    
                    charNumber++;
                }
                else if(iterX->second == -1) // 相等集合扩展
                {
                    iterX->second = iterY->second;
                }
                else if(iterY->second == -1) // 相等集合扩展。
                {
                    iterY->second = iterX->second;
                }
                else
                {
                    // 两个相等集合的合并。
                    if (iterX->second != iterY->second)
                    {
                        int XNumber = iterX->second;
                        for (auto iterMap = sameSet.begin(); iterMap != sameSet.end(); ++iterMap)
                        {
                            if (iterMap->second == XNumber)
                            {
                                iterMap->second = iterY->second;
                            }
                        }
                    }
                }

            }
            else if (iterVec->at(1) == '!')
            {
                differentVec.push_back(iterVec);
            }
            
        }
        // // 未初始化的变量默认与其他变量均不同。
        // for (auto iterMap = sameSet.begin(); result == true && iterMap != sameSet.end(); ++iterMap)
        // {
        //     if (iterMap->second == -1)
        //     {
        //         iterMap->second = charNumber;
                
        //         charNumber++;
        //     }
            
        // }
        // 判断不等式是否成立。
        for (auto iterVec = differentVec.begin(); result == true && iterVec != differentVec.end(); ++iterVec)
        {
            auto x = sameSet.find((*iterVec)->at(0));
            auto y = sameSet.find((*iterVec)->at(3));
            if (x->second != -1 && y->second != -1 && x->second == y->second)
            {
                result = false;
            }
            
        }
        
        return result;
    }
*/

};
// @lc code=end

