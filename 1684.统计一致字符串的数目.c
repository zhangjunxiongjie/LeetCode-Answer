/*
 * @lc app=leetcode.cn id=1684 lang=c
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start


int countConsistentStrings(char * allowed, char ** words, int wordsSize){

    int result = 0;
    bool charMap[26];

    for (int i = 0; i < 26; i++) {

        charMap[i] = false;
    }

    for (int i = 0; i < strlen(allowed); i++) {
        
        charMap[allowed[i] - 'a'] = true;
    }

    for (int i = 0; i < wordsSize; i++) {

        int j = 0;
        for (; j < strlen(words[i]); j++) {

            if (!charMap[words[i][j] - 'a']) {

                // printf("%s\n", words[i]);
                break;
            }
        }

        if (j == strlen(words[i])) {

            result++;
        }
    }

    return result;
}


// @lc code=end

