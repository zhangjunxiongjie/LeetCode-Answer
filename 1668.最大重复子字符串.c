/*
 * @lc app=leetcode.cn id=1668 lang=c
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start


int maxRepeating(char * sequence, char * word){
    
    int repetitionCounter = 0;

    if (strlen(word) > strlen(sequence)) {
        
        return 0;
    }

    for (char *sequencePointer = sequence; sequencePointer < (sequence + strlen(sequence)); ) {

        char *sequencePointer1 = (sequencePointer);
        char *wordPointer = word;
        
        int middleCounter = 0;

        for (; wordPointer < (word + strlen(word)); ) {

            if ((sequencePointer1 < (sequence + strlen(sequence))) &&   (*sequencePointer1) == (*wordPointer)
            ) {                
                sequencePointer1++;
            }
            else {
                break;
            }

            wordPointer++;

            if (wordPointer == (word + strlen(word))) {
                
                wordPointer = word;
                
                middleCounter++;
            }
        }        

        if (middleCounter > repetitionCounter) {

            repetitionCounter = middleCounter;
        }

        if (sequencePointer1 == (sequence + strlen(sequence))) {

            break;
        }

        sequencePointer++;
    }

    return repetitionCounter;
}

// @lc code=end

