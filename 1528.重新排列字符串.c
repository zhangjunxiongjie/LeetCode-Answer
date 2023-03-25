/*
 * @lc app=leetcode.cn id=1528 lang=c
 *
 * [1528] 重新排列字符串
 */

// @lc code=start
char * restoreString(char * s, int* indices, int indicesSize){
    
    char *charVector = malloc(sizeof(char) * (strlen(s) + 1));

    for (int i = 0; i < indicesSize; i++) {

        charVector[indices[i]] = s[i];
    }

    charVector[indicesSize] = '\0';

    return charVector;
}

// @lc code=end

