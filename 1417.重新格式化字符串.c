/*
 * @lc app=leetcode.cn id=1417 lang=c
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start


char * reformat(char * s) {

    char *resultString = malloc (strlen(s) + 1);
    char *resultString1 = malloc (strlen(s) + 1);
    char *charPointer = s; 
    char *numberPointer = s;

    char *resultStringMove = resultString;
    char *resultStringMove1 = resultString1;

    resultString[strlen(s)] = '\0';
    resultString1[strlen(s)] = '\0';

    while (true) {
        
        while (((*charPointer) != '\0') && 
                (((*charPointer) < 'a') || ((*charPointer) > 'z'))
        ) {
            charPointer++;
        }
        
        while (((*numberPointer) != '\0') && 
                (((*numberPointer) < '0') || ((*numberPointer) > '9'))
        ) {
            numberPointer++;
        }
        
        if (((*charPointer) != '\0') && ((*numberPointer) != '\0')) {            

            (*resultStringMove1) = (*numberPointer);
            numberPointer++;
            resultStringMove1++;

            (*resultStringMove1) = (*charPointer);
            charPointer++;
            resultStringMove1++;
        }
        else if (((*charPointer) != '\0') && ((*numberPointer) == '\0')) {
            
            (*resultString1) = '\0';
            break;

        }
        else if (((*charPointer) == '\0') && ((*numberPointer) != '\0')) {

            (*resultStringMove1) = (*numberPointer);
            numberPointer++;
            resultStringMove1++;

            while (((*numberPointer) != '\0') && 
                    (((*numberPointer) < '0') || ((*numberPointer) > '9'))
            ) {
                numberPointer++;
            }

            if ((*numberPointer) == '\0') {
                
                (*resultStringMove1) = '\0';
                break;
            }
            else {

                (*resultString1) = '\0';
                break;
            }            
        }
        else {

            (*resultStringMove1) = '\0';
            break;
        }
        
    }    
     
    charPointer = s; 
    numberPointer = s;

    while (true) {
        
        while (((*charPointer) != '\0') && 
                (((*charPointer) < 'a') || ((*charPointer) > 'z'))
        ) {
            charPointer++;
        }
        
        while (((*numberPointer) != '\0') && 
                (((*numberPointer) < '0') || ((*numberPointer) > '9'))
        ) {
            numberPointer++;
        }
        
        if (((*charPointer) != '\0') && ((*numberPointer) != '\0')) {

            (*resultStringMove) = (*charPointer);
            charPointer++;
            resultStringMove++;

            (*resultStringMove) = (*numberPointer);
            numberPointer++;
            resultStringMove++;

        }
        else if (((*charPointer) != '\0') && ((*numberPointer) == '\0')) {

            (*resultStringMove) = (*charPointer);
            charPointer++;
            resultStringMove++;

            while (((*charPointer) != '\0') && 
                (((*charPointer) < 'a') || ((*charPointer) > 'z'))
            ) {
                charPointer++;
            }

            if ((*charPointer) == '\0') {
                
                (*resultStringMove) = '\0';
                break;
            }
            else {

                (*resultString) = '\0';
                break;
            }
        }
        else if (((*charPointer) == '\0') && ((*numberPointer) != '\0')) {

            (*resultString) = '\0';
            break;
        }
        else {

            (*resultStringMove) = '\0';
            break;
        }
        
    }

    if ((resultString[0] == '\0') && (resultString1[0] == '\0')) {
        
        return resultString;
    }
    else if (resultString[0] != '\0') {
        
        return resultString;
    }
    else if (resultString1[0] != '\0') {
        
        return resultString1;
    }
    else {

        return resultString1;
    }
}

// @lc code=end

