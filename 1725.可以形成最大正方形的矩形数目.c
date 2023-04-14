/*
 * @lc app=leetcode.cn id=1725 lang=c
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start


int countGoodRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize){

    int maximum = 0;
    int resultCounter = 0;

    for (int i = 0; i < rectanglesSize; i++) {

        int middle = fmin(rectangles[i][0], rectangles[i][1]);
        
        if (maximum < middle) {
            
            // printf ("%d, ", middle);

            maximum = middle;
            resultCounter = 1;
        }
        else if (maximum == middle) {
            
            resultCounter++;
        }
    }

    return resultCounter;
}

// @lc code=end

