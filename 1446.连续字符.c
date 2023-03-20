/*
 * @lc app=leetcode.cn id=1446 lang=c
 *
 * [1446] 连续字符
 */

// @lc code=start


int maxPower(char * s){

    int resultCounter = 1;
    
    char *leftP = s, *rightP = s;

    while (true) {

        if ((*rightP) != (*leftP)) {

            if (((rightP - leftP) / sizeof(char)) > resultCounter) {
                
                resultCounter = (int)((rightP - leftP) / sizeof(char));
            }

            leftP = rightP;
            rightP++;

            if ((*leftP) == '\0') {
                break;
            }
        }
        else {

            rightP++;            
        }
    }

    return resultCounter;
}

// @lc code=end

