/*
 * @lc app=leetcode.cn id=2108 lang=c
 *
 * [2108] 找出数组中的第一个回文字符串
 */

// @lc code=start

bool judge_palindrome(char *s)
{
    int leftIndex = 0;
    int rightIndex = (strlen(s) - 1);
    
    while (leftIndex < rightIndex) {

        if (s[leftIndex] != s[rightIndex]) {
            
            return false;
        }

        leftIndex++;
        rightIndex--;
    }

    return true;
}

char * firstPalindrome(char ** words, int wordsSize){

    char *p = "";

    for (int i = 0; i < wordsSize; i++) {

        if (judge_palindrome(words[i])) {
            
            return words[i];
        }
    }

    return p;
}


// @lc code=end

