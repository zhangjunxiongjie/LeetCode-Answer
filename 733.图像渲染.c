/*
 * @lc app=leetcode.cn id=733 lang=c
 *
 * [733] 图像渲染
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void recursion(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int initColor)
{
    // printf ("%d, %d, %d, %d\n", sr, sc, imageSize, *imageColSize);
    
    image[sr][sc] = color;

    if (((sr - 1) >= 0) && (initColor== image[sr - 1][sc])
    ) {
        recursion(image, imageSize, imageColSize, (sr - 1), sc, color, initColor);
    }

    if (((sc - 1) >= 0) && (initColor == image[sr][sc - 1])
    ) {
        recursion(image, imageSize, imageColSize, (sr), (sc - 1), color, initColor);
    }
    
    if (((sr + 1) < imageSize) && (initColor == image[sr + 1][sc])
    ) {
        recursion(image, imageSize, imageColSize, (sr + 1), sc, color, initColor);
    }

    if (((sc + 1) < (*imageColSize)) && (initColor == image[sr][sc + 1])
    ) {
        recursion(image, imageSize, imageColSize, (sr), (sc + 1), color, initColor);
    }    
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
    
    int **resultVector = (int**)malloc (sizeof (int*) * imageSize);
    
    int *resultSize = (int*)malloc(sizeof(int*) * (imageSize));
    (*returnSize) = imageSize;
    (*returnColumnSizes) = resultSize;

    for (int i = 0; i < imageSize; i++) {

        resultVector[i] = (int*)malloc(sizeof(int) * (*imageColSize));
        
        resultSize[i] = (*imageColSize);

        for (int j = 0; j < (*imageColSize); j++) {

            resultVector[i][j] = image[i][j];
        }
    }
    
    if ((resultVector[sr][sc] == color)) {

        
    }
    else {

        recursion(resultVector, imageSize, imageColSize, sr, sc, color, resultVector[sr][sc]);
    }

    return resultVector;
}

// @lc code=end

