/*
 * @lc app=leetcode.cn id=1869 lang=c
 *
 * [1869] 哪种连续子字符串更长
 */

// @lc code=start


bool checkZeroOnes(char * s){

    int leftIndex = 0;

    int oneMaxLength = 0;
    int zeroMaxLength = 0;

    while (leftIndex < strlen(s)) {

        int leftIndexLast = leftIndex;
        while ((leftIndex < strlen(s)) && (s[leftIndex] == '1')) {
            
            leftIndex++;
        }

        if ((leftIndex - leftIndexLast) > oneMaxLength) {
            
            oneMaxLength = (leftIndex - leftIndexLast);
        }

        leftIndexLast = leftIndex;
        while ((leftIndex < strlen(s)) && (s[leftIndex] == '0')) {
            
            leftIndex++;
        }

        if ((leftIndex - leftIndexLast) > zeroMaxLength) {
            
            zeroMaxLength = (leftIndex - leftIndexLast);
        }        
    }
    
    return ((oneMaxLength > zeroMaxLength) ? true : false);

}

// @lc code=end

