/*
 * @lc app=leetcode.cn id=2418 lang=c
 *
 * [2418] 按身高排序
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// void swop(char **str1, char **str2)
// {
//     char *temp = NULL;

//     temp = *str1;
//     *str1 = *str2;
//     *str2 = temp;
// }


char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize){

    for (int heightsIndex = 0; heightsIndex < heightsSize; heightsIndex++) {

        int targetIndex = heightsIndex;
        for (int heightsIndex1 = (targetIndex + 1); heightsIndex1 < heightsSize; heightsIndex1++) {

            if (heights[targetIndex] < heights[heightsIndex1]) {

                targetIndex = heightsIndex1;
            }
        }

        if (targetIndex != heightsIndex) {

            heights[heightsIndex] ^= heights[targetIndex];
            heights[targetIndex] ^= heights[heightsIndex];
            heights[heightsIndex] ^= heights[targetIndex];

            char *middle = names[heightsIndex];
            names[heightsIndex] = names[targetIndex];
            names[targetIndex] = middle;
        }
    }

    (*returnSize) = heightsSize;
    return names;
}

// @lc code=end

