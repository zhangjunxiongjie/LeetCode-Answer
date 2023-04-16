/*
 * @lc app=leetcode.cn id=1370 lang=c
 *
 * [1370] 上升下降字符串
 */

// @lc code=start


char * sortString(char * s){

    char assistantVector[26];
    
    memset(assistantVector, 0, 26);

    for (char *sPointer = s; sPointer < (s + strlen(s)); sPointer++) {

        assistantVector[(*sPointer) - 'a']++;
    }

    char *sPointer = s;
    bool exitFlag = true;

    while (exitFlag) {
        
        exitFlag = false;

        int index = 0;

        while (true) {            

            while ((index < 26) && (assistantVector[index] <= 0)) {
                
                index++;
            }

            if (index >= 26) {

                // exitFlag = false;
                break;
            }
            else {

                exitFlag = true;

                assistantVector[index]--;
                (*sPointer) = index + 'a';
                
                sPointer++;
                index++;
            }            
        }
        
        // printf ("%s\n", s);

        index = 25;

        while (true) {

            while ((index >= 0) && (assistantVector[index] <= 0)) {

                index--;
            }

            if (index < 0) {

                // exitFlag = false;
                break;
            }
            else {

                exitFlag = true;

                assistantVector[index]--;
                (*sPointer) = index + 'a';
                
                sPointer++;
                index--;
            }
        }

        // printf ("%s\n", s);
    }

    return s;
}

// @lc code=end

