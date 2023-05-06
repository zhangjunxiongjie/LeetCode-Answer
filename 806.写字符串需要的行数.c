/*
 * @lc app=leetcode.cn id=806 lang=c
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){

    int *resultVessel = (int*)malloc(sizeof(int) * 2);
    int resultCounter = 0;
    int resultLine = 0;

    for (int i = 0; i < strlen(s); i++) {
        
        if ((resultCounter + widths[(s[i] - 'a')]) > 100) {

            resultLine++;
            resultCounter = widths[(s[i] - 'a')];
        }
        else {

            resultCounter += widths[(s[i] - 'a')];
        }
        
    }

    resultVessel[0] = (resultLine + 1);
    resultVessel[1] = resultCounter;

    (*returnSize) = 2;
    return resultVessel;
}

// @lc code=end

