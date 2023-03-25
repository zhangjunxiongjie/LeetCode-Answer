/*
 * @lc app=leetcode.cn id=1784 lang=c
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start


bool checkOnesSegment(char * s){
    
    int targetStrCounter = 0;

    char *strPointer = s;

    // printf ("%d, %d", '0', '\0');
    
    while ((*strPointer) != '\0') {
        
        char *strPointerLast = strPointer;
        
        // printf ("%c,%c\n", (*strPointer), (*strPointerLast));   

        while (((*strPointer) == '1')) {
            
            strPointer++;
        }
        
        if (strPointerLast != strPointer) {
            
            targetStrCounter++;
        }        

        if ((*strPointer) != '\0') {

            strPointer++;
        }
    }
    
    if (targetStrCounter < 2) {
        return true;
    }
    else {
        return false;
    }
}

// @lc code=end

