/*
 * @lc app=leetcode.cn id=1374 lang=c
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start


char * generateTheString(int n){

    char *resultStr = malloc(sizeof(char) * (n + 1));
    char *strPointer = resultStr;
    
    for (; strPointer < (resultStr + n); strPointer++) {

        (*strPointer) = 'a';
    }
    (*strPointer) = '\0';

    if ((n % 2) == 0) {    

        strPointer--;
        strPointer--;
        (*strPointer) = 'b';
    }
    else {

    }

    return resultStr;
}

// @lc code=end

