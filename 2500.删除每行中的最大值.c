/*
 * @lc app=leetcode.cn id=2500 lang=c
 *
 * [2500] 删除每行中的最大值
 */

// @lc code=start
int deleteGreatestValue(int** grid, int gridSize, int* gridColSize){
    
    int resultTarget = 0;

    for (int i = 0; i < gridSize; i++) {

        for (int j = 0; j < (*gridColSize); j++) {
                        
            int switchIndex = j;

            for (int z = (j + 1); z < (*gridColSize); z++) {

                if (grid[i][switchIndex] > grid[i][z]) {
                    
                    switchIndex = z;
                }
            }

            if (j != switchIndex) {

                int middle = grid[i][switchIndex];
                grid[i][switchIndex] = grid[i][j];
                grid[i][j] = middle;
            }

            // printf ("%d, ", grid[i][j]);
        }

        // printf ("\n");
    }

    for (int i = 0; i < (*gridColSize); i++) {

        int maxNumber = 0;

        for (int j = 0; j < gridSize; j++) {

            if (grid[j][i] > maxNumber) {

                maxNumber = grid[j][i];
            }
        }

        resultTarget += maxNumber;

    }

    return resultTarget;
    
}

// @lc code=end

