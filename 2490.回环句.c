/*
 * @lc app=leetcode.cn id=2490 lang=c
 *
 * [2490] 回环句
 */

// @lc code=start
bool isCircularSentence(char * sentence){

    if (sentence[0] == sentence[strlen(sentence) - 1]) {
        
        char middleChar;
        char *sentencePointer = sentence;

        for (; (*sentencePointer) != '\0'; sentencePointer++) {

            if ((*sentencePointer) != ' ') {

                middleChar = (*sentencePointer);
            }
            else {

                if (middleChar != (*(sentencePointer + 1))) {

                    return false;
                }
            }
        }

        return true;
    }
    else {

        return false;
    }
    
}

// @lc code=end

