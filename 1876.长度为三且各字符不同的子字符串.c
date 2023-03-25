/*
 * @lc app=leetcode.cn id=1876 lang=c
 *
 * [1876] 长度为三且各字符不同的子字符串
 */

// @lc code=start


int countGoodSubstrings(char * s) {

    if (strlen(s) < 3) {

        return 0;
    }    
    else {

        char oneChar = s[0];
        char twoChar = s[1];
        char threeChar = s[2];

        int rightIndex = 2;
        int resultCounter = 0;        

        while (rightIndex < strlen(s)) {
            if ((oneChar != twoChar) && (twoChar != threeChar) && (oneChar != threeChar)
            ) {
                resultCounter++;
            }

            rightIndex++;
            oneChar = twoChar;
            twoChar = threeChar;
            threeChar = s[rightIndex];
        }

        return resultCounter;
    }
    
}

// @lc code=end

