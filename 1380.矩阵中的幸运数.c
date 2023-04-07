/*
 * @lc app=leetcode.cn id=1380 lang=c
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    int *assistantVector = malloc(sizeof(int) * matrixSize);
    int *assistantColVector = malloc(sizeof(int) * (*matrixColSize));
    int *resultVector = malloc(sizeof(int) * (matrixSize));

    memset(assistantVector, 0, (sizeof(int) * matrixSize));
    memset(assistantColVector, 0, (sizeof(int) * (*matrixColSize)));
    memset(resultVector, 0, (sizeof(int) * (matrixSize)));

    for (int i = 0; i < matrixSize; i++) {

        for (int j = 0; j < (*matrixColSize); j++) {

            if (matrix[i][j] < matrix[i][assistantVector[i]]) {

                assistantVector[i] = j;
            }

            if (matrix[i][j] > matrix[assistantColVector[j]][j]) {

                assistantColVector[j] = i;
            }
        }        
    }

    int resultCounter = 0;

    for (int i = 0; i < matrixSize; i++) {

        for (int j = 0; j < (*matrixColSize); j++) {

            if ((assistantVector[i] == j) && (assistantColVector[j] == i)) {
                
                resultVector[resultCounter++] = matrix[i][j];
            }
        }
    }

    (*returnSize) = resultCounter;
    return resultVector;
}

// @lc code=end

