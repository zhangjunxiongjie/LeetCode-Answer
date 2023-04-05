/*
 * @lc app=leetcode.cn id=867 lang=c
 *
 * [867] 转置矩阵
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    
    int **resultVector = malloc(sizeof(int *) * (*matrixColSize));
    
    int *matrixSizePointer = malloc(sizeof(int) * (*matrixColSize));

    for (int i = 0; i < (*matrixColSize); i++) {

        resultVector[i] = malloc(sizeof(int) * matrixSize);
        
        matrixSizePointer[i] = matrixSize;
    }

    for (int i = 0; i < matrixSize; i++) {

        for (int j = 0; j < (*matrixColSize); j++) {

            resultVector[j][i] = matrix[i][j];            
        }        
    }

    (*returnSize) = (*matrixColSize);
    (*returnColumnSizes) = matrixSizePointer;

    return resultVector;
}

// @lc code=end

