/*
 * @lc app=leetcode.cn id=1694 lang=c
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start


char * reformatNumber(char * number){

    char *numberPointer1 = number;

    for (char *numberPointer = number; numberPointer < (number + strlen(number)); numberPointer++) {

        if (('0' <= (*numberPointer)) && ((*numberPointer) <= '9')) {

            (*numberPointer1) = (*numberPointer);
            numberPointer1++;
        }
    }

    (*numberPointer1) = '\0';

    char *resultStr = malloc(sizeof(char) * (strlen(number) + strlen(number) / 3 + 1));

    numberPointer1 = resultStr;

    if ((strlen(number) % 3) == 1) {
        // 2 2 
        char counter = 0;
        
        for (int i = 0; i < (strlen(number) - 4); i++) {

            if (counter == 3) {

                (*numberPointer1) = '-';
                numberPointer1++;

                (*numberPointer1) = (number[i]);
                numberPointer1++;

                counter = 1;
            }
            else {

                (*numberPointer1) = (number[i]);
                numberPointer1++;

                counter++;
            }
        }

        if (counter == 3) {

            (*numberPointer1) = '-';
            numberPointer1++;
        }

        (*numberPointer1) = number[strlen(number) - 4];
        numberPointer1++;

        (*numberPointer1) = number[strlen(number) - 3];
        numberPointer1++;

        (*numberPointer1) = '-';
        numberPointer1++;

        (*numberPointer1) = number[strlen(number) - 2];  
        numberPointer1++;

        (*numberPointer1) = number[strlen(number) - 1];
        numberPointer1++;
    }
    else if (((strlen(number) % 3) == 2) || ((strlen(number) % 3) == 0)) {
        // 3
        
        char counter = 0;
        for (char *numberPointer = number; numberPointer < (number + strlen(number)); numberPointer++) {

            if (counter == 3) {

                (*numberPointer1) = '-';
                numberPointer1++;
                (*numberPointer1) = (*numberPointer);
                numberPointer1++;
                counter = 1;
            }
            else {

                (*numberPointer1) = (*numberPointer);
                numberPointer1++;
                counter++;
            }
        }        
    }

    (*numberPointer1) = '\0';

    return resultStr;
}

// @lc code=end

