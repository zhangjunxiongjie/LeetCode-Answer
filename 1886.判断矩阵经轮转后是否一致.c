/*
 * @lc app=leetcode.cn id=1886 lang=c
 *
 * [1886] 判断矩阵经轮转后是否一致
 */

// @lc code=start


bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){

    bool resultFlag = true;
    bool resultFlag1 = true;
    bool resultFlag2 = true;
    bool resultFlag3 = true;

    for (int i = 0; i < matSize; i++) {

        for (int j = 0; j < (*matColSize); j++) {
            
            if (resultFlag3 && (target[i][j] != mat[i][j])) {
                // 0
                resultFlag3 = false;
            }

            if (resultFlag && (target[i][j] != mat[matSize - 1 - j][i])) {
                // 90
                resultFlag = false;
            }

            if (resultFlag1 && (target[i][j] != mat[matSize - 1 - i][matSize - 1 - j])) {
                // 180
                resultFlag1 = false;
            }

            if (resultFlag2 && (target[i][j] != mat[j][matSize - 1 - i])) {
                // 270
                resultFlag2 = false;
            }
        }
    }

    if (resultFlag || resultFlag1 || resultFlag2 || resultFlag3) {

        return true;
    }
    else {

        return false;
    }    
}

// @lc code=end

