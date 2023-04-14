/*
 * @lc app=leetcode.cn id=1816 lang=c
 *
 * [1816] 截断句子
 */

// @lc code=start


char * truncateSentence(char * s, int k){


    for (char *sPointer = s; sPointer < (s + strlen(s)); sPointer++) {

        if ((*sPointer) == ' ') {

            k--;
            if (k == 0) {

                (*sPointer) = '\0';
                break;
            }
        }
    }

    return s;
}

// @lc code=end

