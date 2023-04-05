/*
 * @lc app=leetcode.cn id=953 lang=c
 *
 * [953] 验证外星语词典
 */

// @lc code=start


bool is_lexicographical_order(char *str1, char *str2, char *assistantVector)
{
    char *str1Pointer = str1;
    char *str2Pointer = str2;
    
    // printf("%s, %s\n", str1Pointer, str2Pointer);

    for (; (((*str1Pointer) != '\0') && ((*str2Pointer) != '\0')); str1Pointer++, str2Pointer++) {

        if (assistantVector[(*str1Pointer) - 'a'] < assistantVector[(*str2Pointer) - 'a']) {

            return true;
        }
        else if (assistantVector[(*str1Pointer) - 'a'] > assistantVector[(*str2Pointer) - 'a']) {

            return false;
        }

        // printf ("%c", *str1Pointer);
    }
    // printf("\n");

    if ((*str1Pointer) == '\0') {
        
        return true;
    }

    if ((*str2Pointer) == '\0') {
        
        return false;
    }

    return false;
}

bool isAlienSorted(char ** words, int wordsSize, char * order){

    char assistantVector[26];

    for (int i = 0; i < strlen(order); i++) {
        
        assistantVector[order[i] - 'a'] = i;
    }
    
    for (int i = 0; i < (wordsSize - 1); i++) {
        
        // printf("%s, %s\n", words[i], words[i + 1]);

        if (!is_lexicographical_order(words[i], words[i + 1], assistantVector)) {

            return false;
        }
    }

    return true;
}

// @lc code=end

