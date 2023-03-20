/*
 * @lc app=leetcode.cn id=1768 lang=c
 *
 * [1768] 交替合并字符串
 */

// @lc code=start


char * mergeAlternately(char * word1, char * word2){
    
    char *resultVector = malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));
    
    unsigned char mainIndex = 0;
    unsigned char i = 0;

    for (; ((i < strlen(word1)) && (i < strlen(word2))); i++) {

        resultVector[mainIndex++] = word1[i];
        resultVector[mainIndex++] = word2[i];
    }

    for (; i < strlen(word1); i++) {

        resultVector[mainIndex++] = word1[i];
    }
    
    for (; i < strlen(word2); i++) {

        resultVector[mainIndex++] = word2[i];
    }

    resultVector[mainIndex++] = '\0';
    
    return resultVector;
}

// @lc code=end

