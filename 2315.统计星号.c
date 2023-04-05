/*
 * @lc app=leetcode.cn id=2315 lang=c
 *
 * [2315] 统计星号
 */

// @lc code=start


int countAsterisks(char * s){

    int resultCounter = 0;
    bool flag = false;

    for (char *strPointer = s; strPointer < (s + strlen(s)); strPointer++) {
        
        if ((*strPointer) == '|') {

            flag = !flag;
        }
        else {

            if ((!flag) && ((*strPointer) == '*')) {

                resultCounter++;
            }
        }
    }

    return resultCounter;
}

// @lc code=end

