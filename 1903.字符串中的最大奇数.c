/*
 * @lc app=leetcode.cn id=1903 lang=c
 *
 * [1903] 字符串中的最大奇数
 */

// @lc code=start


char * largestOddNumber(char * num){
    
    for (int i = (strlen(num) - 1); i >= 0; i--) {
    
        if (((num[i] - '0') % 2) != 0) {
            
            num[i + 1] = '\0';
            break;
        }
        else if (i == 0) {

            num[i] = '\0';
        }
    }

    return num;
}

// @lc code=end

