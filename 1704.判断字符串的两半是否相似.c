/*
 * @lc app=leetcode.cn id=1704 lang=c
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start


bool halvesAreAlike(char * s){
    
    // int assistantVector[5] = {0, 0, 0, 0, 0};
    // int assistantVector1[5] = {0, 0, 0, 0, 0};

    int assistantVector = 0;
    int assistantVector1 = 0;

    bool resultFlag = true;
    int strLength = strlen(s);

    for (int i = 0; i < (strLength / 2); i++) {
        
        int targetIndex = i;  

        if (((s[targetIndex] == 'a') || (s[targetIndex] == 'A')) ||
            ((s[targetIndex] == 'e') || (s[targetIndex] == 'E')) ||
            ((s[targetIndex] == 'i') || (s[targetIndex] == 'I')) ||
            ((s[targetIndex] == 'o') || (s[targetIndex] == 'O')) ||
            ((s[targetIndex] == 'u') || (s[targetIndex] == 'U'))
        ) {
            assistantVector++;
        }

        targetIndex = (strLength - 1 - i);

        if (((s[targetIndex] == 'a') || (s[targetIndex] == 'A')) ||
            ((s[targetIndex] == 'e') || (s[targetIndex] == 'E')) ||
            ((s[targetIndex] == 'i') || (s[targetIndex] == 'I')) ||
            ((s[targetIndex] == 'o') || (s[targetIndex] == 'O')) ||
            ((s[targetIndex] == 'u') || (s[targetIndex] == 'U'))
        ) {
            assistantVector1++;
        }
    }

    /*
    for (int i = 0; i < (strLength / 2); i++) {

        if (s[i]  == 'a') {
            //assistantVector[0]++;
            assistantVector++;
        }
        else if (s[i]  == 'A') {
            //assistantVector[0]++;
            assistantVector++;
        }
        else if (s[i] == 'e') {
            //assistantVector[1]++;
            assistantVector++;
        }
        else if (s[i] == 'E') {
            //assistantVector[1]++;
            assistantVector++;
        }
        else if (s[i] == 'i') {
            //assistantVector[2]++;
            assistantVector++;
        }        
        else if (s[i] == 'I') {
            //assistantVector[2]++;
            assistantVector++;
        }
        else if (s[i] == 'o') {
            //assistantVector[3]++;
            assistantVector++;
        }
        else if (s[i] == 'O') {
            //assistantVector[3]++;
            assistantVector++;
        }
        else if (s[i] == 'u') {
            //assistantVector[4]++;
            assistantVector++;
        }
        else if (s[i] == 'U') {
            //assistantVector[4]++;
            assistantVector++;
        }

        if (s[strLength - 1 - i]  == 'a') {
            //assistantVector1[0]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i]  == 'A') {
            //assistantVector1[0]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'e') {
            //assistantVector1[1]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'E') {
            //assistantVector1[1]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'i') {
            //assistantVector1[2]++;
            assistantVector1++;
        }        
        else if (s[strLength - 1 - i] == 'I') {
            //assistantVector1[2]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'o') {
            //assistantVector1[3]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'O') {
            //assistantVector1[3]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'u') {
            //assistantVector1[4]++;
            assistantVector1++;
        }
        else if (s[strLength - 1 - i] == 'U') {
            //assistantVector1[4]++;
            assistantVector1++;
        }        
    }
    */

    if (assistantVector != assistantVector1) {
        resultFlag = false;
    }

    return resultFlag;
}

// @lc code=end

