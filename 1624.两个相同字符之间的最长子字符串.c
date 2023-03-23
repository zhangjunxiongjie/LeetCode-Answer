/*
 * @lc app=leetcode.cn id=1624 lang=c
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start


int maxLengthBetweenEqualCharacters(char * s){

    int result = -1;
    
    // printf ("%d\n", strlen(s));

    for (int i = 0; i < (strlen(s)); i++) {

        for (int j = (strlen(s) - 1); j > i; j--) {            

            if (s[i] == s[j]) {
                

                if (result < (j - i - 1)) {
                    result = (j - i - 1);
                }
                break;
            }
        }
    }

    return result;
}


// @lc code=end

