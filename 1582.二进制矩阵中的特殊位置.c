/*
 * @lc app=leetcode.cn id=1582 lang=c
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start


int numSpecial(int** mat, int matSize, int* matColSize){
    
    int resultCounter = 0;
    int assistantRows[matSize];
    int assistantCols[*matColSize];
    
    memset(assistantRows, 0, sizeof(int) * matSize);
    memset(assistantCols, 0, sizeof(int) * (*matColSize));

    for (int i = 0; i < matSize; i++) {

        for (int j = 0; j < (*matColSize); j++) {
            
            assistantRows[i] += mat[i][j];
            assistantCols[j] += mat[i][j];
        }
    }

    for (int i = 0; i < matSize; i++) {

        for (int j = 0; j < (*matColSize); j++) {

            if ((assistantRows[i] == 1) && 
                (assistantCols[j] == 1) && 
                (mat[i][j] == 1)
            ) {

                resultCounter++;
            }
        }
    }

    // for (int i = 0; i < matSize; i++) {

    //     printf ("%d, ", assistantRows[i]);
    // }
    
    // printf("\n");

    // for (int i = 0; i < (*matColSize); i++) {

    //     printf ("%d, ", assistantCols[i]);
    // }

    return resultCounter;
}

// @lc code=end

