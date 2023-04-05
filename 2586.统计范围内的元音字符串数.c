/*
 * @lc app=leetcode.cn id=2586 lang=c
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
int vowelStrings(char ** words, int wordsSize, int left, int right){
    
    int resultCounter = 0;

    for (; left <= right; left++) {

        if ((words[left][0] == 'a') ||
            (words[left][0] == 'e') ||
            (words[left][0] == 'i') ||
            (words[left][0] == 'o') || 
            (words[left][0] == 'u')
        ) {
            int strIndex = strlen(words[left]) - 1;

            if ((words[left][strIndex] == 'a') ||
                (words[left][strIndex] == 'e') ||
                (words[left][strIndex] == 'i') ||
                (words[left][strIndex] == 'o') || 
                (words[left][strIndex] == 'u')
            )
            {
                resultCounter++;
            }
        }
    }

    return resultCounter;
}
// @lc code=end

