/*
 * @lc app=leetcode.cn id=2496 lang=c
 *
 * [2496] 数组中字符串的最大值
 */

// @lc code=start
int maximumValue(char ** strs, int strsSize){
    
    int resultTarget = 0;

    for (int i = 0; i < strsSize; i++) {
        
        int middleNumber = strlen(strs[i]);
        int middleNumber1 = 0;
        for (char *strsPointer = strs[i]; (*strsPointer) != '\0'; strsPointer++) {
            
            if ((*strsPointer) <= '9' && (*strsPointer) >= '0') {

                middleNumber1 = (middleNumber1 * 10) + ((*strsPointer) - '0');
            }
            else {

                middleNumber1 = -1;
                break;
            }
        }

        // printf("%d\n", middleNumber);

        if ((-1 == middleNumber1) && (middleNumber > resultTarget)) {

            resultTarget = middleNumber;
        }
        else if ((-1 != middleNumber) && (middleNumber1 > resultTarget)) {

            resultTarget = middleNumber1;
        }
    }

    return resultTarget;
}

// @lc code=end

