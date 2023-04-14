/*
 * @lc app=leetcode.cn id=1859 lang=c
 *
 * [1859] 将句子排序
 */

// @lc code=start


char * sortSentence(char * s){
    
    char *resultStr = malloc(sizeof(char) * (strlen(s) + 1));
    char *resultStrPointer = resultStr;
    char *assistantPointer[9][2];  // 每个单词的前后指针
    char *lastSPointer = s;
    int maxIndex = 0;

    // printf ("%d\n", sizeof(s));

    for (char *sPointer = s; sPointer < (s + strlen(s)); sPointer++) {

        if ((*sPointer) >= '1' && (*sPointer) <= '9') {

            assistantPointer[(*sPointer) - '1'][0] = lastSPointer;
            assistantPointer[(*sPointer) - '1'][1] = sPointer;

            if (((*sPointer) - '1') > maxIndex) {
                
                maxIndex = ((*sPointer) - '1');
            }
        }
        else if ((*sPointer) == ' ') {

            lastSPointer = (sPointer + 1);
        }
    }

    for (int index = 0; index <= maxIndex; index++) {

        // printf ("%c, %c\n", *assistantPointer[index][0], *assistantPointer[index][1]);

        for (char *sPointer = assistantPointer[index][0]; sPointer < assistantPointer[index][1]; sPointer++) {

            // printf ("%c", (*sPointer));            

            (*resultStrPointer) = (*sPointer);      
            resultStrPointer++;
        }

        if (index != maxIndex) {

            (*resultStrPointer) = ' ';
            resultStrPointer++;
        }
        else {

            (*resultStrPointer) = '\0';
            break;
        }
    }
    
    // (*resultStrPointer) = '\0';

    return resultStr;
}

// @lc code=end

