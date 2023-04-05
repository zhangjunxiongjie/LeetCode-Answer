/*
 * @lc app=leetcode.cn id=575 lang=c
 *
 * [575] 分糖果
 */

// @lc code=start


int distributeCandies(int* candyType, int candyTypeSize){

    int candyMaxTypeCounter = 1;

    for (int *candyPointer = candyType; candyPointer < (candyType + candyTypeSize); candyPointer++) {

        int *candyPointer2 = candyPointer;
        for (int *candyPointer1 = (candyPointer + 1); candyPointer1 < (candyType + candyTypeSize); candyPointer1++) {
            
            if ((*candyPointer2) > (*candyPointer1)) {

                candyPointer2 = candyPointer1;
            }
        }

        if (candyPointer2 != candyPointer) {

            int middle = (*candyPointer);
            (*candyPointer) = (*candyPointer2);
            (*candyPointer2) = middle;
        }

        if ((candyPointer != candyType) && ((*(candyPointer - 1)) != (*candyPointer))) {
            
            candyMaxTypeCounter++;
        }

        // printf ("%d, ", *candyPointer);
    }

    return candyMaxTypeCounter < (candyTypeSize / 2) ? candyMaxTypeCounter : (candyTypeSize / 2);

}

// @lc code=end

