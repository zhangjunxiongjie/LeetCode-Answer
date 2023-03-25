/*
 * @lc app=leetcode.cn id=1844 lang=c
 *
 * [1844] 将所有数字用字符替换
 */

// @lc code=start

char shift(char ch, int number)
{
    return (ch + number);
}

char * replaceDigits(char * s){

    char *strVector = malloc(sizeof(char) * (strlen(s) + 1));
    char *strVectorPointer = strVector;
    char charLast;

    for (char *strPointer = s; (*strPointer) != '\0'; strPointer++, strVectorPointer++) {

        if ((*strPointer) <= '9' && (*strPointer) >= '0') {

            (*strVectorPointer) = charLast + (*strPointer) - '0';
        }
        else {

            (*strVectorPointer) = (*strPointer);
            charLast = (*strPointer);
        }
    }

    (*strVectorPointer) = '\0';
    return strVector;
}

// @lc code=end

