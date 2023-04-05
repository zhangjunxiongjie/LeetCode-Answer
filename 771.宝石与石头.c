/*
 * @lc app=leetcode.cn id=771 lang=c
 *
 * [771] 宝石与石头
 */

// @lc code=start


int numJewelsInStones(char * jewels, char * stones){

    int resultSum = 0;
    char *jewelsPointer = jewels;
    char *stonesPointer = stones;

    while (jewelsPointer < (jewels + strlen(jewels))) {

        stonesPointer = stones;

        for (char *stonesPointer1 = stones; (*stonesPointer1) != '\0'; stonesPointer1++) {

            if ((*stonesPointer1) == (*jewelsPointer)) {

                resultSum++;
            }
            else {
                // printf("%c, ", (*stonesPointer1));
                if (stonesPointer != stonesPointer1) {

                    (*stonesPointer) = (*stonesPointer1);                    
                }   
                // 
                stonesPointer++;                             
            }
        }
        // printf("\n");
        // if () {
            (*stonesPointer) = '\0';
        // }

        // printf("%s\n", stones);
        jewelsPointer++;
    }

    return resultSum;
}

// @lc code=end

