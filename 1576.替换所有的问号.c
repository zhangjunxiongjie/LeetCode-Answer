/*
 * @lc app=leetcode.cn id=1576 lang=c
 *
 * [1576] 替换所有的问号
 */

// @lc code=start


char * modifyString(char * s){

    char middleChar = ('z' + 1);

    for (char *strPointer = s; strPointer < (s + strlen(s)); strPointer++) {
        
        while ((strPointer < (s + strlen(s))) && ((*strPointer) == '?')) {

            if (middleChar == ('z' + 1)) {
                middleChar = 'a';

                (*strPointer) = middleChar;
            }
            else if (middleChar == (*strPointer)) {

                middleChar++;
                if (middleChar == ('z' + 1)) {
                    middleChar = 'a';
                }
                (*strPointer) = middleChar;
            }
            else {

                middleChar++;
                if (middleChar == ('z' + 1)) {
                    middleChar = 'a';
                }
                (*strPointer) = middleChar;
            }

            strPointer++;

            while ((strPointer < (s + strlen(s))) && (middleChar == (*strPointer))) {

                if (middleChar == ('z' + 1)) {
                    
                    middleChar = 'a';
                    (*(strPointer - 1)) = middleChar;
                }
                else {

                    middleChar++;
                    if (middleChar == ('z' + 1)) {
                        middleChar = 'a';
                    }
                    (*(strPointer - 1)) = middleChar;
                }                
            }
        }

        middleChar = (*strPointer);
    }

    return s;
}

// @lc code=end

