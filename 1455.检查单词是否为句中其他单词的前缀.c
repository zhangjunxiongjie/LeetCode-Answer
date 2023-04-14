/*
 * @lc app=leetcode.cn id=1455 lang=c
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start


int isPrefixOfWord(char * sentence, char * searchWord){

    int wordCounter = 1;
    int resultCounter = -1;
    bool compareFlag = true;
    char *searchWordPointer = searchWord;

    for (char *sentencePointer = sentence; sentencePointer < (sentence + strlen(sentence)); sentencePointer++) {

        if (compareFlag) {
            
            // printf ("%c, ", (*sentencePointer));

            if ((*searchWordPointer) == (*sentencePointer)) {

                searchWordPointer++;                

                if (searchWordPointer >= (searchWord + strlen(searchWord))) {

                    resultCounter = wordCounter;
                    break;
                }
            }
            else {

                if ((*sentencePointer) == ' ') {

                    compareFlag = true;

                    searchWordPointer = searchWord;

                    wordCounter++;
                }
                else {

                    compareFlag = false;
                }                
            }
        }
        else if ((*sentencePointer) == ' ') {
            
            // printf ("\n");

            compareFlag = true;

            searchWordPointer = searchWord;

            wordCounter++;
        }

    }

    return resultCounter;
}

// @lc code=end

