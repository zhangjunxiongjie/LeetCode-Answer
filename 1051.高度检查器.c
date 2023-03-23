/*
 * @lc app=leetcode.cn id=1051 lang=c
 *
 * [1051] 高度检查器
 */

// @lc code=start


int heightChecker(int* heights, int heightsSize){

    int resultCounter = 0;
    int *cacheVector = malloc(sizeof(int) * heightsSize);
    
    memcpy(cacheVector, heights, (sizeof(int) * heightsSize));

    for (int i = 0; i < heightsSize; i++) {
        
        int targetIndex = i;

        for (int j = i; j < heightsSize; j++) {

            if (heights[targetIndex] > heights[j]) {
                targetIndex = j;
            }
        }
        
        if (targetIndex != i) {

            int middle = heights[i];

            heights[i] = heights[targetIndex];
            heights[targetIndex] = middle;
        }

        if (heights[i] != cacheVector[i]) {
            
            resultCounter++;
        }
    }
    
    /*
    for (int i = 0; i < heightsSize; i++) {

        printf ("%d,",heights[i]);
    }
    printf("\n");

    for (int i = 0; i < heightsSize; i++) {

        printf ("%d,",cacheVector[i]);
    }
    printf("\n");
    */
    return resultCounter;
}

// @lc code=end

