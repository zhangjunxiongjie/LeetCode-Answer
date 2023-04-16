/*
 * @lc app=leetcode.cn id=1309 lang=c
 *
 * [1309] 解码字母到整数映射
 */

// @lc code=start


char * freqAlphabets(char * s){

    char *sPointer1 = s;

    for (char *sPointer = s; sPointer < (s + strlen(s)); sPointer++) {

        if (((sPointer + 2) < (s + strlen(s))) && ((*(sPointer + 2)) == '#')) {

            (*sPointer1) = (((*sPointer) - '0') * 10) + ((*(sPointer + 1)) - '0') - 1 + 'a';

            sPointer1++;
            sPointer += 2;
        }
        else {

            (*sPointer1) = ((*sPointer) - '0') - 1 + 'a';

            sPointer1++;
        }
    }

    (*sPointer1) = '\0';

    return s;
}

// @lc code=end

