/*
 * @lc app=leetcode.cn id=2351 lang=c
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start


char repeatedCharacter(char * s){

    int charAssistant = 0;
    char resultChar;

    for (char *charPointer = s; charPointer < (s + strlen(s)); charPointer++) {

        if (charAssistant & (1 << ((*charPointer) - 'a'))) {
            
            // printf ("%c\n" , *charPointer);
            resultChar = (*charPointer);
            break;
        }
        else {
            charAssistant |= (1 << ((*charPointer) - 'a'));
        }

        // printf ("%d\n", charAssistant);
    }

    return resultChar;
}

// @lc code=end

