/*
 * @lc app=leetcode.cn id=1790 lang=c
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
bool areAlmostEqual(char * s1, char * s2){
    
    bool resultFlag = true;
    char *s1FirstPointer = NULL;
    char *s2FirstPointer = NULL;
    bool firstIntoFlag = true;

    for (char *s1Pointer = s1, *s2Pointer = s2; s1Pointer < (s1 + strlen(s1)); s1Pointer++, s2Pointer++) {

        if ((*s1Pointer) != (*s2Pointer)) {
            
            if (firstIntoFlag) {

                if (s1FirstPointer == NULL) {

                    s1FirstPointer = s1Pointer;
                    s2FirstPointer = s2Pointer;
                }
                else {
                    if (((*s1Pointer) == (*s2FirstPointer)) && 
                        ((*s2Pointer) == (*s1FirstPointer))
                    ) {
                        resultFlag = true;                    
                        s1FirstPointer = NULL;
                        s2FirstPointer = NULL;
                        firstIntoFlag = false;
                    }
                    else {
                        resultFlag = false;
                        break;
                    }
                }
            }
            else {
                resultFlag = false;
                break;
            }
        }
    }

    if (s1FirstPointer != NULL) {
        resultFlag = false;
    }
    
    return resultFlag;
}

// @lc code=end

