/*
 * @lc app=leetcode.cn id=832 lang=c
 *
 * [832] 翻转图像
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes){
    
    int **resultVector = (int**)malloc (sizeof (int*) * imageSize);
    
    int *resultSize = (int*)malloc(sizeof(int*) * (imageSize));
    (*returnSize) = imageSize;
    (*returnColumnSizes) = resultSize;

    for (int i = 0; i < imageSize; i++) {

        resultVector[i] = (int*)malloc(sizeof(int) * (*imageColSize));
        
        resultSize[i] = (*imageColSize);

        for (int j = 0; j < (*imageColSize); j++) {

            resultVector[i][j] = image[i][j];
            
            if (resultVector[i][j]) {

                resultVector[i][j] = 0;
            }
            else {

                resultVector[i][j] = 1;
            }            
        }
    }

    for (int i = 0; i < ((*imageColSize) / 2); i++) {

        for (int j = 0; j < imageSize; j++) {

            resultVector[j][i] ^= resultVector[j][(*imageColSize) - i - 1];
            resultVector[j][(*imageColSize) - i - 1] ^= resultVector[j][i];
            resultVector[j][i] ^= resultVector[j][(*imageColSize) - i - 1];

        }
    }

    return resultVector;
}

// @lc code=end

