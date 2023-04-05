/*
 * @lc app=leetcode.cn id=1614 lang=c
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start


int maxDepth(char * s){
    
    int resultCounter = 0;
    int resultMaximum = 0;

    for (int i = 0; i < strlen(s); i++) {

        if (s[i] == '(') {

            resultCounter++;
            if (resultMaximum < resultCounter) {
                
                resultMaximum = resultCounter;
            }
        }
        else if (s[i] == ')') {

            resultCounter--;
        }
    }

    return resultMaximum;
}

// @lc code=end

