/*
 * @lc app=leetcode.cn id=917 lang=c
 *
 * [917] 仅仅反转字母
 */

// @lc code=start


char * reverseOnlyLetters(char * s){

    char *strVector = malloc(sizeof(char) * strlen(s));    
    int strVectorIndex = 0;

    for (char *strPointer = s; strPointer < (s + strlen(s)); strPointer++) {

        if ((((*strPointer) <= 'z') && ((*strPointer) >= 'a')) ||
            ((*strPointer) <= 'Z') && ((*strPointer) >= 'A')
        ) {
            // printf ("%c, ", (*strPointer));

            if (strVectorIndex < strlen(s)) {

                strVector[strVectorIndex++] = (*strPointer);
                // printf ("%c, ", strVector[strVectorIndex - 1]);
            }
        }
    }
    // printf ("\n");

    for (char *strPointer = s; strPointer < (s + strlen(s)); strPointer++) {

        if ((((*strPointer) <= 'z') && ((*strPointer) >= 'a')) ||
            ((*strPointer) <= 'Z') && ((*strPointer) >= 'A')
        ) {
            if ((strVectorIndex - 1) >= 0) {

                (*strPointer) = strVector[strVectorIndex - 1];
                
                strVectorIndex--;
            }
        }
    }
    printf ("\n");

    free(strVector);

    return s;
}

// @lc code=end

