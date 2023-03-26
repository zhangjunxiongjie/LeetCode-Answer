/*
 * @lc app=leetcode.cn id=2506 lang=c
 *
 * [2506] 统计相似字符串对的数目
 */

// @lc code=start
int similarPairs(char ** words, int wordsSize){
    
    int assistantBitVessel[wordsSize];
    int resultTarget = 0;

    memset(assistantBitVessel, 0, (sizeof(int) * wordsSize));

    for (int i = 0; i < wordsSize; i++) {

        for (char *wordsPointer = words[i]; (*wordsPointer) != '\0'; wordsPointer++) {

            assistantBitVessel[i] |= (1 << ((*wordsPointer) - 'a'));
        }
    }

    for (int i = 0; i < wordsSize; i++) {

        for (int j = (i + 1); j < wordsSize; j++) {
            
            if (assistantBitVessel[i] == assistantBitVessel[j]) {
                
                printf("%d, %x, %d, %x\n", i, assistantBitVessel[i], j, assistantBitVessel[j]);

                resultTarget++;
            }
        }        
    }

    return resultTarget;
}

// @lc code=end

