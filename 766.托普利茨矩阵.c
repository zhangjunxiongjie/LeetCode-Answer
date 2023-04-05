/*
 * @lc app=leetcode.cn id=766 lang=c
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start


bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){

    bool resultFlag = true;
    int matrixLeft = 0;
    int matrixCol = 0;

    for (matrixLeft = 0, matrixCol = 0; matrixLeft < matrixSize; matrixLeft++) {
        
        // printf ("%d:\n", matrix[matrixLeft][matrixCol]);

        for (int i = (matrixLeft + 1), j = (matrixCol + 1); (i < matrixSize) && (j < (*matrixColSize)); i++, j++) {
            
            // printf("%d, ", matrix[i][j]);

            if (matrix[i][j] != matrix[matrixLeft][matrixCol]) {
                
                resultFlag = false;
                return resultFlag;
            }
        }
        // printf("\n");
    }
    // printf("\n");

    for (matrixLeft = 0, matrixCol = 0; matrixCol < (*matrixColSize); matrixCol++) {

        // printf ("%d:\n", matrix[matrixLeft][matrixCol]);

        for (int i = (matrixLeft + 1), j = (matrixCol + 1); (i < matrixSize) && (j < (*matrixColSize)); i++, j++) {

            // printf("%d, ", matrix[i][j]);

            if (matrix[i][j] != matrix[matrixLeft][matrixCol]) {
                
                resultFlag = false;
                return resultFlag;
            }
        }

        // printf("\n");
    }

    return resultFlag;
}
// @lc code=end

