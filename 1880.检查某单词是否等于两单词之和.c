/*
 * @lc app=leetcode.cn id=1880 lang=c
 *
 * [1880] 检查某单词是否等于两单词之和
 */

// @lc code=start


bool isSumEqual(char * firstWord, char * secondWord, char * targetWord){

    int firstWordValue = 0;
    int secondWordValue = 0;
    int targetWordValue = 0;

    for (char *firstWordPointer = firstWord; firstWordPointer < (firstWord + strlen(firstWord)); firstWordPointer++) {

        firstWordValue *= 10;
        firstWordValue += ((*firstWordPointer) - 'a');
    }

    for (char *secondWordPointer = secondWord; secondWordPointer < (secondWord + strlen(secondWord)); secondWordPointer++) {

        secondWordValue *= 10;
        secondWordValue += ((*secondWordPointer) - 'a');
    }

    for (char *targetWordPointer = targetWord; targetWordPointer < (targetWord + strlen(targetWord)); targetWordPointer++) {

        targetWordValue *= 10;
        targetWordValue += ((*targetWordPointer) - 'a');
    }
    
    // printf ("%d, %d, %d\n", firstWordValue, secondWordValue, targetWordValue);

    if ((firstWordValue + secondWordValue) == targetWordValue) {

        return true;
    }
    else {

        return false;
    }    
}


// @lc code=end

