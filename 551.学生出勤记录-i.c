/*
 * @lc app=leetcode.cn id=551 lang=c
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start


bool checkRecord(char * s){

    bool result = true;    
    int ACounter = 0;

    for (char *strPointer = s; (*strPointer) != '\0'; strPointer++) {

        int LCounter = 0;    
        while (((*strPointer) != '\0') && ((*strPointer) == 'L')) {
            
            LCounter++;
            strPointer++;
        }

        if ((LCounter) >= 3) {

            result = false;   
            break;         
        }

        if ((*strPointer) == '\0') {

            break;
        }

        if ((*strPointer) == 'A') {

            ACounter++;
            if (ACounter >= 2) {

                result = false;
                break;
            }
        }        
    }

    return result;
}

// @lc code=end

