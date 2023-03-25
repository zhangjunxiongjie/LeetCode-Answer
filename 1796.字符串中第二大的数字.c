/*
 * @lc app=leetcode.cn id=1796 lang=c
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start


int secondHighest(char * s){

    int firstNumber = -1;
    int secondNumber = -1;

    for (char *strPointer = s; (*strPointer) != '\0'; strPointer++) {

        // printf("%c,", (*strPointer));

        if (((*strPointer) <= '9') && ((*strPointer) >= '0')) {
                        

            if (((*strPointer) - '0') > firstNumber) {

                secondNumber = firstNumber;
                firstNumber = ((*strPointer) - '0');
            }
            else if ((((*strPointer) - '0') > secondNumber) && (((*strPointer) - '0') != firstNumber)) {

                secondNumber = ((*strPointer) - '0');
            }
        }
    }

    return secondNumber;
}


// @lc code=end

