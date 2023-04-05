/*
 * @lc app=leetcode.cn id=2319 lang=c
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

// @lc code=start


bool checkXMatrix(int** grid, int gridSize, int* gridColSize){

    for (int i = 0; i < gridSize; i++) {

        for (int j = 0; j < (*gridColSize); j++) {

            if ((i == j) || ((i + j) == (gridSize - 1))) {

                if (grid[i][j] == 0) {
                    
                    return false;
                }
            }
            else {

                if (grid[i][j] != 0) {

                    return false;
                }
            }
        }
    }

    return true;
}

// @lc code=end

