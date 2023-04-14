/*
 * @lc app=leetcode.cn id=1544 lang=c
 *
 * [1544] 整理字符串
 */

// @lc code=start


char * makeGood(char * s){
    
    //(c1 ^ c2) == 32 判断两个字母是否一个大写一个小写

    bool exitFlag = true;

    while (exitFlag) {

        char *sPointer = s;
        char *resultStrPointer = s;
        
        exitFlag = false;

        for (; sPointer < (s + strlen(s)); sPointer++) {

            if (((sPointer + 1) < (s + strlen(s))) && (((*sPointer) ^ (*(sPointer + 1))) == 32)) {

                sPointer++;
                exitFlag = true;
            }
            else {

                (*resultStrPointer) = (*sPointer);                
                resultStrPointer++;
            }
        }

        (*resultStrPointer) = '\0';

        // printf ("%s\n", resultStr);
    }

    return s;

    /*
    bool exitFlag = true;

    while (exitFlag) {

        char *sPointer = s;
        char *resultStrPointer = s;
        
        exitFlag = false;

        for (; sPointer < (s + strlen(s)); sPointer++) {

            if ((sPointer + 1) < (s + strlen(s)) && (abs((*sPointer) - (*(sPointer + 1))) == 32)) {

                sPointer++;
                exitFlag = true;
            }
            else {

                (*resultStrPointer) = (*sPointer);                
                resultStrPointer++;
            }
        }

        (*resultStrPointer) = '\0';

        // printf ("%s\n", resultStr);
    }

    return s;
    */
}

// @lc code=end

