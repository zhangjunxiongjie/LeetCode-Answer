/*
 * @lc app=leetcode.cn id=844 lang=c
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start


bool backspaceCompare(char * s, char * t){

    char *sPointer = s + strlen(s) - 1;
    char *tPointer = t + strlen(t) - 1;

    while (true) {

        int charCounter = 0;

        while ((sPointer >= s) && ((*sPointer == '#') || (charCounter != 0))) {

            if ((*sPointer) == '#') {

                charCounter++;
            }
            else {

                charCounter--;
            }
            
            sPointer--;
        }
        
        charCounter = 0;

        while ((tPointer >= t) && ((*tPointer == '#') || (charCounter != 0))) {

            if ((*tPointer) == '#') {

                charCounter++;
            }
            else {

                charCounter--;
            }
            
            tPointer--;
        }

        if ((sPointer >= s) && (tPointer >= t)) {
            
            if ((*sPointer) != (*tPointer)) {
                
                return false;
            }

        }
        else if ((sPointer >= s)) {

            if ((*sPointer) != '#') {

                return false;
            }
            else {

                return true;
            }
        }
        else if ((tPointer >= t)) {

            if ((*tPointer) != '#') {

                return false;
            }
            else {

                return true;
            }
        }
        else {

            break;
        }        
        
        sPointer--;
        tPointer--;
    }

    return true;
}

// @lc code=end

