/*
 * @lc app=leetcode.cn id=1678 lang=c
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start


char * interpret(char * command){
    
    char *commandPointer1 = command;

    for (char *commandPointer = command; (*commandPointer) != '\0'; ) {

        if ((*commandPointer) == 'G') {
            
            *(commandPointer1++) = 'G';
            
            commandPointer++;
        }
        else if (((*commandPointer) == '(') && 
                ((*(commandPointer + 1)) == ')')
        ) {

            *(commandPointer1++) = 'o';

            commandPointer++;
            commandPointer++;
        }
        else if (((*commandPointer) == '(') && 
                 ((*(commandPointer + 1)) == 'a') &&
                 ((*(commandPointer + 2)) == 'l') &&
                 ((*(commandPointer + 3)) == ')')
        ) {
            *(commandPointer1++) = 'a';
            *(commandPointer1++) = 'l';

            commandPointer++;
            commandPointer++;
            commandPointer++;
            commandPointer++;
        }

        // printf ("%c, ", *commandPointer);
    }

    (*commandPointer1) = '\0';

    return command;
}

// @lc code=end

