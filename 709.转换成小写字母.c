/*
 * @lc app=leetcode.cn id=709 lang=c
 *
 * [709] 转换成小写字母
 */

// @lc code=start


char * toLowerCase(char * s){

    for (char *strPointer = s; (*strPointer) != '\0'; strPointer++) {

        if ((*strPointer) <= 'Z' && (*strPointer) >= 'A') {

            (*strPointer) = (*strPointer) - 'A' + 'a';
        }
        else {
            (*strPointer) = (*strPointer);
        }
    }

    return s;
}

// @lc code=end

