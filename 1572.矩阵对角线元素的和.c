/*
 * @lc app=leetcode.cn id=1572 lang=c
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start


int diagonalSum(int** mat, int matSize, int* matColSize){

    int sum = 0;

    for (int i = 0; i < matSize; i++) {

        sum += mat[i][i];
        sum += mat[i][matSize - 1 - i];
    }

    if ((matSize % 2) == 1) {

        sum -= mat[(matSize - 1) / 2][(matSize - 1) / 2];
    }

    return sum;
}

// @lc code=end

